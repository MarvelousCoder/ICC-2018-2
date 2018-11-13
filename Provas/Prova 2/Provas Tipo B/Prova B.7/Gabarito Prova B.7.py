dicionario = {
'.':'E',
'-':'T',
'.-':'A',
'---':'O',
'..':'I',
'-.':'N',
'...':'S',
'.-.':'R',
'....':'H',
'.-..':'L',
'-..':'D',
'-.-.':'C',
'..-':'U',
'--':'M',
'..-.':'F',
'.--.':'P',
'--.':'G',
'.--':'W',
'-.--':'Y',
'-...':'B',
'...-':'V',
'-.-':'K',
'-..-':'X',
'.---':'J',
'--.-':'Q',
'--..':'Z',
'.----':'1',
'..---':'2',
'...--':'3',
'....-':'4',
'.....':'5',
'-....':'6',
'--...':'7',
'---..':'8',
'----.':'9',
'-----':'0',
'.-.-.-':'.',
'--..--':',',
'..--..':'?',
'-....-':'-',
}

listaMorse = []
codigo = input()

while (codigo != '..-. .. --'):
	listaMorse.append(codigo)
	codigo = input()

traducao = ''

for palavraMorse in listaMorse:
	letrasMorse = palavraMorse.split()
	for letra in letrasMorse:
		traducao = traducao + dicionario[letra]
	traducao += '\n'

print(traducao)
