import customtkinter as ctk
from PIL import Image

# Use um dicionário ou lista para rastrear a seleção, mas manteremos as variáveis
# globais para simplicidade, conforme seu código original.
guerreiro = False
curandeira = False
ladino = False
maga = False
bardo = False
arqueiro = False
team_size = 0

char_pick = ctk.CTk()
char_pick.title("Seleção de Personagens")
char_pick.geometry("340x350")
char_pick.grid_columnconfigure((0, 1, 2), weight=1) # Faz os botões se expandirem
char_pick.grid_rowconfigure((0, 1, 2, 3), weight=0) # Faz as lihas não se expandirem

label_char_pick = ctk.CTkLabel(char_pick, text="Monte sua equipe (Máx: 4)")
label_char_pick.grid(row=0, column=0, columnspan=3, pady=10) # POSICIONADO!

label_msg = ctk.CTkLabel(char_pick, text="Selecione seus heróis")
label_msg.grid(row=3, column=0, columnspan=3, pady=10) # POSICIONADO!

#endereço e inicialização das imagns
try:
    img_guerreiro = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/guerreiro.png")
    ctkimg_guerreiro = ctk.CTkImage(dark_image = img_guerreiro, light_image = img_guerreiro, size = (200, 200))

    img_curandeira = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/curandeira.png")
    ctkimg_curandeira = ctk.CTkImage(dark_image = img_curandeira, light_image = img_curandeira, size = (200, 200))

    img_ladino = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/ladino.png")
    ctkimg_ladino = ctk.CTkImage(dark_image = img_ladino, light_image = img_ladino, size = (200, 200))

    img_maga = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/maga.png")
    ctkimg_maga = ctk.CTkImage(dark_image = img_maga, light_image = img_maga, size = (200, 200))

    img_bardo = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/bardo.png")
    ctkimg_bardo = ctk.CTkImage(dark_image = img_bardo, light_image = img_bardo, size = (200, 200))

    img_arqueiro = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/arqueiro.png")
    ctkimg_arqueiro = ctk.CTkImage(dark_image = img_arqueiro, light_image = img_arqueiro, size = (200, 200))

except FileNotFoundError:
    label_msg.configure(text = "Imagens não encontradas")
    ctkimg_guerreiro = ctk.CTkImage(Image.new('RGB', (80, 80), color = 'red'), size=(80, 80))
    ctkimg_curandeira = ctk.CTkImage(Image.new('RGB', (80, 80), color = 'red'), size=(80, 80))
    ctkimg_ladino = ctk.CTkImage(Image.new('RGB', (80, 80), color = 'red'), size=(80, 80))
    ctkimg_maga = ctk.CTkImage(Image.new('RGB', (80, 80), color = 'red'), size=(80, 80))
    ctkimg_bardo = ctk.CTkImage(Image.new('RGB', (80, 80), color = 'red'), size=(80, 80))
    ctkimg_arqueiro = ctk.CTkImage(Image.new('RGB', (80, 80), color = 'red'), size=(80, 80))

team_size = 0

def iniciar_batalha():
    global tela_batalha
    tela_batalha = ctk.CTkToplevel()
    tela_batalha.title("Batalha")
    tela_batalha.geometry("400x300")

    tela_batalha.focus

def pick_char(name, char_status, button):
    global team_size
    char_status_global = globals().get(name)

    if char_status_global == True:
        label_msg.configure(text = f"{name} já está no time")
        return
    
    if team_size >= 4:
        label_msg.configure(text = "Limite de grupo atingido (4/4)")
        return 
    
    globals()[name] = True
    team_size += 1
    button.configure(state = "disabled", fg_color = "gray")
    label_msg.configure(text = f"{name} selecionado! Espaços: {team_size}/4")
    
    if team_size == 4:
        iniciar_batalha()

def pick_guerreiro():
    pick_char("guerreiro", guerreiro, but_char1)

def pick_curandeira():
    pick_char("curandeira", curandeira, but_char2)

def pick_ladino():
    pick_char("ladino", ladino, but_char3)

def pick_maga():
    pick_char("maga", maga, but_char4)

def pick_bardo():
    pick_char("bardo", bardo, but_char5)

def pick_arqueiro():
    pick_char("arqueiro", arqueiro, but_char6)

but_char1 = ctk.CTkButton(char_pick, text = "", image = ctkimg_guerreiro, command = pick_guerreiro)
but_char1.grid(column = 0, row = 1, pady = 10, padx = 10, sticky="nsew")

but_char2 = ctk.CTkButton(char_pick, text = "", image = ctkimg_curandeira, command = pick_curandeira)
but_char2.grid(column = 1, row = 1, pady = 10, padx = 10, sticky="nsew")

but_char3 = ctk.CTkButton(char_pick, text = "", image = ctkimg_ladino, command = pick_ladino)
but_char3.grid(column = 2, row = 1, pady = 10, padx = 10, sticky="nsew")

but_char4 = ctk.CTkButton(char_pick, text = "", image = ctkimg_maga, command = pick_maga)
but_char4.grid(column = 0, row = 2, pady = 10, padx = 10, sticky="nsew")

but_char5 = ctk.CTkButton(char_pick, text = "", image = ctkimg_bardo, command = pick_bardo)
but_char5.grid(column = 1, row = 2, pady = 10, padx = 10, sticky="nsew")

but_char6 = ctk.CTkButton(char_pick, text = "", image = ctkimg_arqueiro, command = pick_arqueiro)
but_char6.grid(column = 2, row = 2, pady = 10, padx = 10, sticky="nsew")



char_pick.mainloop()