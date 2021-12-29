import datetime
import calendar
import tkinter
root=tkinter.Tk()
f=tkinter.Frame(root,width=250,height=150)
f.pack_propagate(0)
f.pack()
#
today = datetime.date.today()
#
cal=calendar.TextCalendar(6)
calstr=cal.formatmonth(today.year,today.month)

l=tkinter.Label(f,text=calstr,justify=tkinter.LEFT,font=('Courier',12))
l.pack(side=tkinter.TOP)
tkinter.mainloop()
