#importa a biblioteca Flask
from flask import Flask

#cria aplicação web 
app = Flask(__name__)

#liga a função ao endereço inicial do site
@app.route("/")
def hello_world():
    return "<p>Olá, Mundo!</p>"