class User():
    def __init__(self, info):
        self.u_id = info["u_id"]
        self.username = info["tg_name"]
        self.admin = info["admin"]

    def __repr__(self):
        return "{}: {}, is admin: {}".format(self.u_id, self.username, self.admin)
    