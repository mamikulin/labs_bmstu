import datetime

class Message():
    def __init__(self, info):
        self.id = info["id"]
        self.date = info["date"]
        self.text = info["text"]

    def __repr__(self):
        return "{}: {}, {}".format(self.id, str(datetime.datetime.strptime(self.date, '%Y-%m-%dT%H:%M:%S.%fZ'))[:-7], self.text)
    
    def get_text(self):
        return self.text

    def get_date(self):
        return str(datetime.datetime.strptime(self.date, '%Y-%m-%dT%H:%M:%S.%fZ'))[:-10]