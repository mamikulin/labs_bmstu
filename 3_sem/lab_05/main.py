import telebot
from telebot import types

from config import config

bot = telebot.TeleBot(config.TOKEN)

@bot.message_handler(commands=['start'])
def send_welcome(message):
    markup = types.InlineKeyboardMarkup()
    button1 = types.InlineKeyboardButton(text = 'Кнопка 1')
    button2 = types.InlineKeyboardButton(text = 'Кнопка 2')
    button2 = types.InlineKeyboardButton(text = 'Кнопка 3')
    markup.add(button1, button2, button3)
    bot.send_message(message.from_user.id, "По кнопке ниже можно перейти на сайт хабра", reply_markup = markup)

@bot.message_handler(commands=['button'])
def button_message(message):
    markup = types.InlineKeyboardMarkup()
    button1 = types.InlineKeyboardButton(text = 'Кнопка 1')
    button2 = types.InlineKeyboardButton(text = 'Кнопка 2')
    button3 = types.InlineKeyboardButton(text = 'Кнопка 3')
    markup.add(button1, button2, button3)
    bot.send_message(reply_markup = markup)


@bot.message_handler(func=lambda message: True)
def echo_all(message):
    if message.text == 'Кнопка 1':
      # Действия при нажатии на кнопку 1
      bot.reply_to(message, 'Вы нажали на Кнопку 1')

    elif message.text == 'Кнопка 2':
        # Действия при нажатии на кнопку 2
        bot.reply_to(message, 'Вы нажали на Кнопку 2')

    elif message.text == 'Кнопка 3':
        # Действия при нажатии на кнопку 3
        bot.reply_to(message, 'Вы нажали на Кнопку 3')
    
    else:
        bot.reply_to(message, message.text)

bot.polling(none_stop=True, interval=0)