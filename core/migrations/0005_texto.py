# Generated by Django 4.2.6 on 2023-12-10 14:22

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('core', '0004_tirinha'),
    ]

    operations = [
        migrations.CreateModel(
            name='Texto',
            fields=[
                ('id', models.IntegerField(primary_key=True, serialize=False)),
                ('titulo', models.CharField(max_length=255)),
                ('data', models.CharField(max_length=255)),
                ('link', models.CharField(max_length=255)),
                ('resumo', models.CharField(max_length=255)),
                ('area', models.CharField(max_length=255)),
                ('keywords', models.CharField(max_length=255)),
                ('autor', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='core.autor')),
            ],
            options={
                'abstract': False,
            },
        ),
    ]
