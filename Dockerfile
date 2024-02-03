# Utilisez une image de base avec le support C++ (par exemple, gcc)
FROM gcc:latest

# Créez un répertoire de travail dans le conteneur
WORKDIR /app

# Copiez les fichiers source depuis le répertoire src dans le conteneur
COPY src /app/src

# Copiez le fichier main.cpp depuis la racine dans le conteneur
COPY main.cpp /app/main.cpp

# Copiez les fichiers de test depuis le répertoire tests dans le conteneur
COPY tests /app/tests

# Compilez votre projet C++ avec les tests
RUN g++ -o mon_executable tests/test_main.cpp main.cpp -lgtest -lgtest_main -pthread

# Commande par défaut à exécuter lorsque le conteneur démarre
CMD ["./mon_executable"]
