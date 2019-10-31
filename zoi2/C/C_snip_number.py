
def snip_number(str):
    n=len(str)
 
 #initialize Opt Table
 # Opt[i,j] = min number of snips in the substring str[i...j]
 
    Opt=[[0 for i in range(n)] for j in range(n) ]
 
 #Opt of single char is 0
    for i in range(n):
     Opt[i][i] = 0
 
 #Opt for adjacent chars is 1 if different, 0 otherwise
    for i in range(n-1):
     Opt[i][i+1]= 1 if str[i]!=str[i+1] else 0
 
 
# we now define sil as (s)substring (i)interval (l) length of the
# interval [i,j] --- sil=(j-i +1) and j = i+sil-1
 
# we compute Opt table entry for each sil length and
# starting index i
 
    for sil in range(3, n+1):
     for i in range(n-sil+1):
       j = i+sil-1
       if (str[i] == str[j] and Opt[i+1][j-1]==0):
         Opt[i][j] = 0
       else:
         snip= min( [(Opt[i][t]+ Opt[t+1][j] + 1 ) for t in range(i,j-1)])
         Opt[i][j] = snip

    return Opt[0][len(str)-1]
#end function snip_number()
mystr=[""for i in range(4)]         
mystr[0]="abc"
mystr[1]="ohiho"
mystr[2]="cabacdbabdc"
mystr[3]="amanaplanacanalpanama aibohphobia "


for i in range(4):
     print(mystr[i], "has snip number:", snip_number(mystr[i]))
     
# abc has snip number: 2
# ohiho has snip number: 0
# cabacdbabdc has snip number: 2
# amanaplanacanalpanama aibohphobia  has snip number: 1
