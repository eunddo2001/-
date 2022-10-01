cipher = '''RGCTBHBYRDIDKRNPZUTWLDEDNRCCULEUMNUBYITCTEPLCNNYRNBTIKDKNKTWEMTFDIECDKNTWM
UBTMLKBRCCULGCTBHKNYRNRMUKUBOMUCPCDIHULNTEUNYUMOKDIEBMPZNTEMRZYPURBYGCTBHB
TINRDIKRBMPZNTEMRZYDBYRKYTWNYUZMUADTOKGCTBHRNDXUKNRXZRILNMRIKRBNDTILRNREUI
UMRCCPMUZMUKUINULRKRXUMHCUNMUUFYUMULRNRITLUKRMUMUZMUKUINULGPCURWKNYUNDXUKN
RXZZMTAUKNYRNNYUNMRIKRBNDTILRNRUJDKNULFYUINYUGCTBHFRKBMURNULKDIBUURBYGCTBH
BTINRDIKDIWTMXRNDTIRGTONNYUGCTBHZMUADTOKNTDNNYUPUWWUBNDAUCPWTMXRBYRDIBTXZR
MUCDIHULCDKNLRNRKNMOBNOMUFDNYURBYRLLDNDTIRCGCTBHCDIHDIENTNYUTIUKGUWTMUDNBT
IKUSOUINCPGCTBHBYRDINMRIKRBNDTIKRMUDMMUAUMKDGCUDINYRNTIBUNYUPRMUMUBTMLULNY
ULRNRDIRIPEDAUIGCTBHBRIITNGURCNUMULMUNMTRBNDAUCPFDNYTONRCNUMDIERCCKOGKUSOU
INGCTBHK'''
#cipher = cipher.replace('\n','')

freq = {}
for i in range(65,91):
    freq[chr(i)] = cipher.count(chr(i))
sorted_freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)
#print(sorted_freq, end='\n\n')

diagram={}
for i in range(65,91):
    for j in range(65,91):
        if cipher.count(chr(i)+chr(j))>2:
            diagram[chr(i)+chr(j)] = cipher.count(chr(i)+chr(j))
sorted_diagram = sorted(diagram.items(), key=lambda x: x[1], reverse=True)
#print(sorted_diagram, end='\n\n')

triagram={}
for i in range(65,91):
    for j in range(65,91):
        for k in range(65,91):
            if cipher.count(chr(i)+chr(j)+chr(k))>2:
                triagram[chr(i)+chr(j)+chr(k)] = cipher.count(chr(i)+chr(j)+chr(k))
sorted_triagram = sorted(triagram.items(), key=lambda x: x[1], reverse=True)
#print(sorted_triagram, end='\n\n')

quatragram={}
for i in range(65,91):
    for j in range(65,91):
        for k in range(65,91):
            for l in range(65,91):
                if cipher.count(chr(i)+chr(j)+chr(k)+chr(l))>2:
                    quatragram[chr(i)+chr(j)+chr(k)+chr(l)] = cipher.count(chr(i)+chr(j)+chr(k)+chr(l))
sorted_quatragram = sorted(quatragram.items(), key=lambda x: x[1], reverse=True)
#print(sorted_quatragram, end = '\n\n')

plain = cipher
plain = plain.replace('U', 'e')
plain = plain.replace('N', 't')
plain = plain.replace('Y', 'h')
plain = plain.replace('R', 'a')
plain = plain.replace('M', 'r')
plain = plain.replace('T', 'o')
plain = plain.replace('P', 'y')
plain = plain.replace('D', 'i')
plain = plain.replace('I', 'n')
plain = plain.replace('B', 'c')
plain = plain.replace('K', 's')
plain = plain.replace('C', 'l')
plain = plain.replace('E', 'g')
plain = plain.replace('G', 'b')
plain = plain.replace('H', 'k')
plain = plain.replace('Z', 'p')
plain = plain.replace('W', 'f')
plain = plain.replace('L', 'd')
plain = plain.replace('F', 'w')
plain = plain.replace('O', 'u')
plain = plain.replace('A', 'v')
plain = plain.replace('S', 'q')
plain = plain.replace('J', 'x')
plain = plain.replace('X', 'm')
print(plain)

for i in plain:
    if i.isupper() == True:
        plain = plain.replace(i, '-')
print(plain)
