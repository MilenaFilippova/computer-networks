#!/usr/bin/python3
 
import pymysql
import sys
 
con = pymysql.connect('localhost', 'test1',
    'ei7veeChu4bo', 'network')
 
def agi_command(cmd):
        '''Write out the command and return the response'''
        print(cmd)
        sys.stdout.flush() #clear the buffer
        return sys.stdin.readline().strip() # strip whitespace
 
asterisk_env = {} # read AGI env vars from Asterisk
while True:
        line = sys.stdin.readline().strip()
        if not len(line):
                break
        var_name, var_value = line.split(':', 1)
        asterisk_env[var_name] = var_value.strip()
 
response = agi_command('ANSWER')
 
response = agi_command('GET DATA /usr/share/asterisk/sounds/recordings/1 10000 1')
 
if 'timeout' in response:
        response = agi_command('STREAM FILE /usr/share/asterisk/sounds/recordings/2 ""')
        sys.exit(0)
 
account = response.split('=', 1)[1]
 
accounts = []
balance = -100000
 
caller_id = asterisk_env["agi_callerid"]
 
with con:
 
    cur = con.cursor()
    cur.execute("SELECT * from accounts WHERE phone=" + str(caller_id) + "and number=" + str(account))
   
    balance = -1000000
    id, phone, number, balance = cur.fetchone()
 
if balance != -1000000:
    response = agi_command("SET VARIABLE BALANCE %s" %(balance))
    response = agi_command("SET VARIABLE CHECK %s" %(1))
    response = agi_command('SAY NUMBER %s ""' % (balance))
else:
    response = agi_command("SET VARIABLE CHECK %s" %(-1))
 
sys.exit(0)
