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


response = agi_command('GET DATA /usr/share/asterisk/sounds/recordings/hellobalance 10000 1')

if 'timeout' in response:
        response = agi_command('STREAM FILE /usr/share/asterisk/sounds/recordings/error ""')
        sys.exit(0)

account = response.split('=', 1)[1]

caller_id = asterisk_env["agi_callerid"]

with con:

    cur = con.cursor()
    cur.execute("SELECT * from subscribers WHERE phone=\'" + str(caller_id) + "\' and number=\'" + str(account) + "\'")
    data = cur.fetchone()

    print(data)
    if data != None:
        id, phone, number, balance = data

if data != None:
    response = agi_command("SET VARIABLE BALANCE %s" %(balance))
    response = agi_command("SET VARIABLE CHECK %s" %(1))
    response = agi_command('SAY NUMBER %s ""' % (balance))
else:
    response = agi_command("SET VARIABLE CHECK %s" %(-1))

sys.exit(0)

