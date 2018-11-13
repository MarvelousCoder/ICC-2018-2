isbn = input()

while(isbn != 'FIM'):
  x = []
  count = 0
  for caracter in isbn:
    if caracter not in '-*/':
      count += 1
      if caracter == 'x' or caracter == 'X':
        coeficiente = 10
      else:
        coeficiente = int(caracter)
      x.append(coeficiente)
    else:
      pass


  if count == 13: 
      formula = (10-(x[0]+ 3*x[1]+ x[2]+ 3*x[3]+ x[4]+ 3*x[5]+ x[6]+ 3*x[7]+ x[8]+ 3*x[9]+
                          x[10]+ 3*x[11])%10)%10

      if formula == x[12]:
          print("OK")
      else:
          print("%s ERRO" %(isbn))
  else:
      print("%s ERRO" %(isbn))
  isbn = input()
