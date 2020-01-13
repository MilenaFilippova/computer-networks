#Вам необходимо написать приложение на любом языке программирования, которое будет принимать в качестве аргументов 
#IP-адрес и порт коммутатора (длину кабеля в котором нужно измерить).


#import telnetlib
#telnetlibМодуль обеспечивает Telnetкласс , который реализует протокол Telnet.
from telnetlib import Telnet
#https://docs.python.org/3/library/telnetlib.html для работы с консолью

#IP='10.90.90.29'
#port='1-5'

IP = input("For analistic enter your IP: ")
telnet = Telnet(IP)
#вводим порт  длину кабеля в котором нужно измерить
port = input('Enter port : ')

#имя пользователя и пароль
telnet.read_until(b'UserName')
telnet.write(b'\n')
telnet.read_until(b'PassWord')
telnet.write(b'\n')
#пропускаем ненужные строки
telnet.read_until(b'#')


#формируем команду для консоли cable_diag ports номер_порта
mycommand = 'cable_diag ports ' + str(port) + '\n'
encod_mycommand = mycommand.encode(encoding = 'ascii',errors = 'strict')
#print ("Кодированная строка: ", encod_mycommand)
telnet.write(encod_mycommand)
print(encod_mycommand)



result = telnet.read_until(b'DES')
# print(result.decode('utf-8'))
for res in result.decode('utf-8').split('\n'):
    #print ("Декодированная строка(result.decode): ", res)
    # аргументы результ. строки:
    #   Port   Type      Link Status          Test Result          Cable Length (M)
    #   делим строку по пробеллам(на слова) 
    string = res.split()
    if len(string)==6:
        if string[4] == 'OK':
            print("Приблизительная длина кабеля :", str(string[5]))
        elif string[4] == 'Mismatched':
            print("	Возникли ошибки при диагностике кабеля, требуется перезапустить тест на том же порту")
        else:
            print("Кабель не работает")
    elif len(string)==7:    
        if string[4] == 'Line'  and  string[5] == 'Driver':
            print("Обнаружено высокое электрическое сопротивление на другой стороне кабеля")
        else:
            print("Кабель не работает")
    elif len(string)==8:        
        if string[4]=='Short'  and  string[5]=='in' and string[6]=='Cable' :
            print("Короткое замыкание в кабеле")
        elif string[4]=='Open'  and  string[5]=='in' and string[6]=='Cable' :
            print("Кабель, подключенный к порту коммутатора, поврежден или не подключен на другой стороне")
    else:
        print("Error!")
