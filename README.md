![Titulo do jornal](https://i.imgur.com/MYiz0oc.png)

# Por que um jornal?
>Não existe "povo" sem memória.
>
>Desde os tempos mais remotos da história humana, o homem procura deixar marcas de sua passagem por esta vida. No início, pinturas em cavernas. 
>Depois, rústicas construções de pedra e à medida que evoluiu, escritas nas mais diversas formas, monumentos, esculturas, grandes obras.
>
>Um jornal é a grande reserva de memória de um povo.
>
>**Folha Guara-Sul, 1999**


## Tutorial para instalação
> **ATENÇÃO:**  Para executar o projeto é necessário ter sqlite3 e python instalados em sua máquina.

Clone o projeto e execute os seguintes passos:

Para compilar:
```bash
  make
```
Para executar:
```bash
  make run
```

Em outra aba do terminal crie um ambiente virtual para visualizar a interface:
```bash
  python3 -m venv env
```
Ative o ambiente virtual:
```bash 
  source env/bin/activate
```
Instale as dependências do arquivo requirements.txt:
```bash
  pip install -r requirements.txt
```

Ative o servidor local:
```bash
  python3 manage.py runserver
```
Pronto, acesse [127.0.0.1:8000/core](127.0.0.1:8000/core) e garanta sua dose diária de ciência!


## Créditos
- [CompFood](https://github.com/INF112-Programacao2/20222-team-7): molde para o uso de Django e implementação do banco de dados.
- [Fundação Biblioteca Nacional](https://bndigital.bn.gov.br/): inspirações para a construção da estética do jornal.
- [Ciência Hoje das crianças](https://cienciahoje.periodicos.capes.gov.br/revista-chc): exemplo de divulgação científica com linguagem acessível.