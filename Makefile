TARGET=jornal
CC=g++
LD=g++
LDFLAGS= -l sqlite3
OBJS= src/main.cpp src/Administrador.cpp src/Anuncio.cpp src/Artigo.cpp src/Autor.cpp src/Comentario.cpp src/Leitor.cpp src/Texto.cpp src/Tirinha.cpp src/Usuario.cpp

jornal:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

clean:
	rm -rf *.o
	rm -rf $(TARGET)

run:
	./$(TARGET)