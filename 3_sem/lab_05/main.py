import telebot
from telebot import types

from config import config
from src.processing.user import *
from src.processing.message import *

bot = telebot.TeleBot(config.TOKEN)

@bot.message_handler(commands=["start"])
def start(message):

    welcome = types.InlineKeyboardMarkup()
    btn_messages = types.InlineKeyboardButton("Посмореть сообщения", callback_data = "messages")
    welcome.add(btn_messages)

    reg = registration(message.from_user)
    if reg == 1:
        btn_tour = types.InlineKeyboardButton("Описание", callback_data = "tour")
        welcome.add(btn_tour)
        
    elif reg == 2: 
        btn_admin = types.InlineKeyboardButton("Написать сообщение", callback_data = "admin")
        btn_admin_del = types.InlineKeyboardButton("Удалить сообщение", callback_data = "admin_del")
        welcome.add(btn_admin)
        welcome.add(btn_admin_del)
    else:
        pass

    bot.send_message(message.chat.id, "Приветствую", reply_markup=welcome)



@bot.callback_query_handler(func = lambda callback: True)
def callback_message(callback):
    if callback.data == "tour":
        back = telebot.types.InlineKeyboardMarkup()
        btn_back = types.InlineKeyboardButton("Назад", callback_data = "back")
        back.row(btn_back)

        bot.edit_message_text("text", callback.message.chat.id, callback.message.message_id, reply_markup = back)

    if callback.data == "back":
        bot.send_message(callback.message.chat.id, "/start")
        start(callback.message)

    if callback.data == "admin":
        bot.send_message(callback.message.chat.id, "Новое сообщение: ")
        bot.register_next_step_handler(callback.message, add)

    if callback.data == "admin_del":
        bot.send_message(callback.message.chat.id, "ID сообщение: ")
        bot.register_next_step_handler(callback.message, delete)
        

    if callback.data == "messages":
        messages = read_db()
        for message in messages:
            bot.send_message(callback.message.chat.id, """{}
                {}""".format(message.get_text(), message.get_date()), parse_mode = "HTML") 




bot.polling(none_stop = True)