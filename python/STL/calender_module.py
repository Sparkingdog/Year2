import calendar
cal = calendar.TextCalendar(firstweekday=6)#6 = sunday,0=Monday
print(cal.prmonth(2021,12))#pr = print
print(cal.formatmonth(2022,1))