from django.db import models

class Usuario(models.Model):
    class Meta:
        abstract = True

    id = models.IntegerField(primary_key=True)
    nome = models.CharField(max_length=255)
    email = models.CharField(max_length=255)

class Adm(Usuario):
    senha = models.CharField(max_length=255)

class Autor(Usuario):
    formacao = models.CharField(max_length=255)
    area = models.CharField(max_length=255)

class Artigo(models.Model):
    class Meta:
        abstract = True

    id = models.IntegerField(primary_key=True)
    titulo = models.CharField(max_length=255)
    autor = models.ForeignKey(Autor, on_delete=models.CASCADE)
    data = models.CharField(max_length=255)
    link = models.CharField(max_length=255)
    favoritado = models.BooleanField(default=False)

class Anuncio(Artigo):
    texto = models.CharField(max_length=1000)
    logo = models.CharField(max_length=255)

class Tirinha(Artigo):
    imagem = models.CharField(max_length=255)

class Texto(Artigo):
    resumo = models.CharField(max_length=1000)
    area = models.CharField(max_length=255)
    keywords = models.CharField(max_length=255)

class Leitor(Usuario):
    assinatura_ativada = models.BooleanField()
    data_inicial_contrato = models.CharField(max_length=255)

class Comentario(models.Model):
    id = models.IntegerField(primary_key=True)
    texto = models.CharField(max_length=500)
    autor = models.ForeignKey(Autor, on_delete=models.CASCADE)
    artigo = models.ForeignKey(Texto, on_delete=models.CASCADE)