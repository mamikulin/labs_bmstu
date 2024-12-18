import telebot
from telebot import types

from telegram import Update, ReplyKeyboardMarkup
from telegram.ext import Application, CommandHandler, MessageHandler, ContextTypes, ConversationHandler, filters
import requests

# Define states for ConversationHandler
MAIN_MENU, SERVICES_MENU, CURRENCY = range(3)

# Currency API URL
CURRENCY_API_URL = "https://api.exchangerate-api.com/v4/latest/"

# Main menu keyboard
main_menu_keyboard = [
    ["Сервисы"],
    ["Контакты"]
]
main_menu_markup = ReplyKeyboardMarkup(main_menu_keyboard, resize_keyboard=True)

# Services menu keyboard
services_menu_keyboard = [
    ["Конвертер валют"],
    ["Назад"]
]
services_menu_markup = ReplyKeyboardMarkup(services_menu_keyboard, resize_keyboard=True)

async def start(update: Update, context: ContextTypes.DEFAULT_TYPE) -> int:
    await update.message.reply_text(
        "Привет! Я ваш помощник. Выберите действие:",
        reply_markup=main_menu_markup
    )
    return MAIN_MENU

async def main_menu(update: Update, context: ContextTypes.DEFAULT_TYPE) -> int:
    text = update.message.text
    if text == "Сервисы":
        await update.message.reply_text("Выберите сервис:", reply_markup=services_menu_markup)
        return SERVICES_MENU
    elif text == "Контакты":
        await update.message.reply_text("Контакты: support@example.com, +123456789")
    else:
        await update.message.reply_text("Пожалуйста, используйте кнопки для навигации.")
    return MAIN_MENU

async def services_menu(update: Update, context: ContextTypes.DEFAULT_TYPE) -> int:
    text = update.message.text
    if text == "Конвертер валют":
        await update.message.reply_text("Введите данные в формате: сумма исходная_валюта целевая_валюта (например, 100 USD EUR)")
        return CURRENCY
    elif text == "Назад":
        await update.message.reply_text("Возврат в главное меню:", reply_markup=main_menu_markup)
        return MAIN_MENU
    else:
        await update.message.reply_text("Пожалуйста, используйте кнопки для навигации.")
        return SERVICES_MENU

async def currency(update: Update, context: ContextTypes.DEFAULT_TYPE) -> int:
    try:
        data = update.message.text.split()
        if len(data) != 3:
            await update.message.reply_text("Неверный формат. Попробуйте снова.")
            return CURRENCY

        amount, from_currency, to_currency = data
        amount = float(amount)

        response = requests.get(f"{CURRENCY_API_URL}{from_currency.upper()}").json()
        rates = response.get("rates")

        if not rates or to_currency.upper() not in rates:
            await update.message.reply_text("Неверная валюта. Попробуйте снова.")
            return CURRENCY

        rate = rates[to_currency.upper()]
        converted_amount = amount * rate
        await update.message.reply_text(f"{amount} {from_currency.upper()} = {converted_amount:.2f} {to_currency.upper()}")
    except Exception as e:
        await update.message.reply_text("Ошибка при конвертации валюты. Попробуйте снова позже.")
    return SERVICES_MENU

async def cancel(update: Update, context: ContextTypes.DEFAULT_TYPE) -> int:
    await update.message.reply_text("До встречи!", reply_markup=ReplyKeyboardMarkup([[]], resize_keyboard=True))
    return ConversationHandler.END

def main() -> None:
    application = Application.builder().token("7263596285:AAEsMeJ-XXVfMDdsgawGERYhXvSj2Z3z4dA").build()

    conv_handler = ConversationHandler(
        entry_points=[CommandHandler("start", start)],
        states={
            MAIN_MENU: [MessageHandler(filters.TEXT & ~filters.COMMAND, main_menu)],
            CURRENCY: [MessageHandler(filters.TEXT & ~filters.COMMAND, currency)],
            SERVICES_MENU: [MessageHandler(filters.TEXT & ~filters.COMMAND, services_menu)],
            
        },
        fallbacks=[CommandHandler("cancel", cancel)],
    )

    application.add_handler(conv_handler)

    application.run_polling()

if __name__ == "__main__":
    main()

