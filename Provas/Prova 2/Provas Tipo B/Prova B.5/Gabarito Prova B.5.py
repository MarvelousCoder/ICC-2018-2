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

  if count == 10: 
      formula = (10*x[0] + 9*x[1] + 8*x[2] + 7*x[3] + 6*x[4] + 5*x[5] + 4*x[6] + 
        3*x[7] + 2*x[8] + 1*x[9])%11
      if formula == 0:
          print("OK")
      else:
          print("%s ERRO" %(isbn))
  else:
      print("%s ERRO" %(isbn))
  isbn = input()
