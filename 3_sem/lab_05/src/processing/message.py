import json
from src.message import *
from datetime import datetime


def read_db():
    with open("data/messages.json", "r") as messages_db:
        messages = json.load(messages_db)
    
    messages_r = []

    for message in messages["messages"]: 
        
        messages_r.append(Message(message))

    return messages_r


def add(message):

    with open("data/messages.json", "r") as messages_db:
        messages = json.load(messages_db)

    messages["messages"].append({"id": len(messages["messages"]), "date": datetime.now().strftime('%Y-%m-%dT%H:%M:%S.%fZ'), "text": message.text})
    for _ in messages["messages"]: 
        print(_)
    with open("data/messages.json", "w") as messages_db:
        json.dump(messages, messages_db, indent = 3)


def delete(message):
    with open("data/messages.json", "r") as messages_db:
        messages = json.load(messages_db)
        
    for message_ in messages["messages"]: 
        if message_["id"] == int(message.text):
            messages["messages"].pop(int(message.text))
            print(messages["messages"])
            
            with open("data/messages.json", "w") as messages_db:
                json.dump(messages, messages_db, indent = 3)