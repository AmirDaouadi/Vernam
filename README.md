Instructions pour la compilation :

1 : écrivez votre message dans un fichier

2: par la suite compilez en tapant la commande suivante : gcc vernam.c -o vernam -ansi -Wall

3: puis grace a la commande : ./vernam -cl "nom du fichier" "Clé générer" "Génératiuon inutile" . Générer la clé aléatoirement 

4: A présent , crypter en vernam grâce a la commande : ./vernam -cd "fichier avec le message" "fichier clé" "fichier crypté avec le message qui sera générer"

5: Puis pour finir décryptez en vernam en grace a la commande : ./vernam -dc "fichier qui est crypter" "fichier clé" "fichier qui sera décrypter"   