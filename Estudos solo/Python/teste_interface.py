#importa a biblioteca que cria interfaces
import customtkinter as ctk

#importa a classe imagem da biblioteca pillow
from PIL import Image

#aparencia da interface
ctk.set_appearance_mode('light')

path = r"C:\Users\LEO\Desktop\GitHub\Estudos solo\Python\teste.png"

img = Image.open(path)

def verify():
    user = campo_user.get()
    senha = campo_pass.get()

    if user != "Leonardo":
        retorno.configure(text = 'Login negado, usuário ou senha incorreta', text_color = 'red')
        return 0
    if senha != "12435687":
        retorno.configure(text = 'Login negado, usuário ou senha incorreta', text_color = 'red')
        return 0
    
    retorno.configure(text = 'Login feito com sucesso, bem-vindo Leonardo', text_color = 'green')
    app_popup = ctk.CTkToplevel(app)
    app_popup.title("Interface de Admin")
    teste = ctk.CTkImage(dark_image=img, light_image=img, size = (1000, 1000))
    label = ctk.CTkLabel(app_popup, image = teste, compound = "top")
    label.pack(pady = 30)
    return 1

#cria a interface
app = ctk.CTk()
#nome da interface
app.title("Sistema de Login")
#tamanho da interface
app.geometry('300x300')

#campos de interface (label, entry, button)
label_user = ctk.CTkLabel(app, text = 'Usuário')
label_user.pack(pady = 10)

campo_user = ctk.CTkEntry(app, placeholder_text = 'Digite seu usuário')
campo_user.pack(pady = 10)

label_pass = ctk.CTkLabel(app, text = 'Senha')
label_pass.pack(pady = 10)

campo_pass = ctk.CTkEntry(app, placeholder_text = 'Digite sua senha', show = '*')
campo_pass.pack(pady = 10)

botao_login = ctk.CTkButton(app, text = 'Login', command = verify, corner_radius = 32, fg_color = "#C850C0", hover_color = "#4158D0", border_color = "#FFCC70", border_width = 2)
botao_login.pack(pady = 10)

retorno = ctk.CTkLabel(app, text = '')
retorno.pack(pady = 10)

app.mainloop()
