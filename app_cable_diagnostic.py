#Вам необходимо написать приложение на любом языке программирования, которое будет принимать в качестве аргументов 
#IP-адрес и порт коммутатора (длину кабеля в котором нужно измерить).


#import telnetlib
#telnetlibМодуль обеспечивает Telnetкласс , который реализует протокол Telnet.
from telnetlib import Telnet
#https://docs.python.org/3/library/telnetlib.html для работы с консолью

IP = input("For analistic enter your IP: ")
#вводим порт  длину кабеля в котором нужно измерить
port =(int)( input('Enter port : '))
telnet = Telnet(IP)


#формируем команду для консоли cable_diag ports номер_порта
mycommand = 'cable_diag ports ' + str(port) + '\n'
encod_mycommand = mycommand.encode(encoding = 'ascii',errors = 'strict')
#print ("Кодированная строка: ", encod_mycommand)
telnet.write(encod_mycommand)



result = telnet.read_until(b'DES')
# print(result.decode('utf-8'))
for res in result.decode('utf-8').split('\n'):
    #print ("Декодированная строка(result.decode): ", res)
#    Port   Type      Link Status          Test Result          Cable Length (M)
    strig = res.split()
    if strig[3] == 'OK':
            print("Приблизительная длина кабеля :", str(strig[4]))
    elif strig[3] == 'Short in Cable':
            print("Короткое замыкание в кабеле")
    elif strig[3] == 'Open in Cable': 
            print("Кабель, подключенный к порту коммутатора, поврежден или не подключен на другой стороне")
    elif strig[3] == 'Mismatched':
            print("	Возникли ошибки при диагностике кабеля, требуется перезапустить тест на том же порту")
    elif strig[3] == 'Line Driver':
            print("К данному порту не подключён кабель")
    elif strig[3] == 'Line Driver':
            print("Обнаружено высокое электрическое сопротивление на другой стороне кабеля")
