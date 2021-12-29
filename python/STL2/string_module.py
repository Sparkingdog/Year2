from string import Template
import string
'a' in string.ascii_lowercase
string.printable
string.whitespace

s = Template('$who likes $what')

print(s.substitute(who='tim', what='kung pao'))
