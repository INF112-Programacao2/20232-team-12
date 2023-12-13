from django.http import HttpResponse
from django.template import loader
from django.shortcuts import render

from .models import Texto
from .models import Anuncio
from .models import Tirinha

def core(request):
  mytexts = Texto.objects.select_related('autor').all()
  myads = Anuncio.objects.select_related('autor').all()
  mycomics = Tirinha.objects.select_related('autor').all()

  context = {
    'mytexts': mytexts,
    'myads': myads,
    'mycomics': mycomics
  }
  return render(request, 'jornal.html', context)

