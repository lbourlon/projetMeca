#compilation du code Rubik's Cube

# Options de compilation
CFLAGS = 
#CFLAGS = -g

# nom des librairies a lier
LNAME = -lm

# nom de l executable
EXEC=main.exe

#liste des fichiers sources (on aurait pu utiliser SRC= $(wildcard *.c)
SRC=  main.c fonctions.c resolution.c

#liste des fichiers objets
OBJ= $(SRC:.c=.o)

# action declenchee par defaut
all: $(EXEC)
    

# compilation des fichiers sources en fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $^

# compilation de l exectubale a partir des fichier sources
$(EXEC) : $(OBJ)
	$(CC)  -o $@ $^ $(LNAME)
	chmod +x $(EXEC)
	echo compilation terminee
	echo Rubikx away
	
clean:
	rm -rf *.o
	ls
