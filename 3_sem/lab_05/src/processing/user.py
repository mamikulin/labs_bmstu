from src.user import *
import json

def registration(user_info):
    
    
    with open("data/users.json", "r") as users_db:
        users = json.load(users_db)
    

    user_r = []
   
    for user in users["users_data"]: 
        
        user_r.append(User(user))

    for user in user_r: 
        if user.u_id == user_info.id:
            if user.admin == 1: 
                return 2
            return 0

    users_db.close()

    users["users_data"].append({"u_id": user_info.id, "tg_name": user_info.username, "admin": 0 })


    with open("data/users.json", "w") as users_db:
        json.dump(users, users_db, indent = 3)

    return 1