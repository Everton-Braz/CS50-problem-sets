import csv


codigo = []
nomes = set()
siglas = []


with open("UF.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        nome = row["NOME"].strip().upper()
        nomes.add(nome)
        # if not nome in nomes:
        #     nomes.append(nome)

for nome in sorted(nomes,reverse=True,):
    print(nome)




