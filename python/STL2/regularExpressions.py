import re
1-2-2018
2-3-2018
#:% s /\([0-9][0-9]*) -\([0-9][0-9] *\) -\([0-9][0-9] *\)\2/-\1-\3/g
#%s :on all lines
#%s/pattern to search
#\d is a another way to replace [0-9]