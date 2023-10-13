from django.http import HttpResponse
from django.template import loader

from django.http import HttpResponse
from django.template import loader
from .models import Adm

def core(request):
  myadms = Adm.objects.all().values()
  template = loader.get_template('all_adms.html')
  context = {
    'myadms': myadms,
  }
  return HttpResponse(template.render(context, request))