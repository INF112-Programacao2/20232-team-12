# Generated by Django 4.2.6 on 2023-12-10 20:07

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('core', '0005_texto'),
    ]

    operations = [
        migrations.CreateModel(
            name='Leitor',
            fields=[
                ('id', models.IntegerField(primary_key=True, serialize=False)),
                ('nome', models.CharField(max_length=255)),
                ('email', models.CharField(max_length=255)),
                ('assinatura_ativada', models.BooleanField()),
                ('data_inicial_contrato', models.CharField(max_length=255)),
            ],
            options={
                'abstract': False,
            },
        ),
        migrations.AddField(
            model_name='anuncio',
            name='favoritado',
            field=models.BooleanField(default=False),
        ),
        migrations.AddField(
            model_name='texto',
            name='favoritado',
            field=models.BooleanField(default=False),
        ),
        migrations.AddField(
            model_name='tirinha',
            name='favoritado',
            field=models.BooleanField(default=False),
        ),
    ]