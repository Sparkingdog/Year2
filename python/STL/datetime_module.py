from datetime import *
today = date.today()
twoweeks = today + timedelta(weeks=2)
nextyear = today.replace(year=2022) 
now = datetime.now()
print(today)
print(nextyear)
print(twoweeks)