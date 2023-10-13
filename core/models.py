from django.db import models

class Adm(models.Model):
    id = models.IntegerField(primary_key=True)
    nome = models.CharField(max_length=255)
    email = models.CharField(max_length=255)
    senha = models.CharField(max_length=255)
