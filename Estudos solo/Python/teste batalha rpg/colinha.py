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
char_pick.grid_rowconfigure((0, 1, 2, 3), weight=0) # As linhas não precisam expandir

label_char_pick = ctk.CTkLabel(char_pick, text="Monte sua equipe (Máx: 4)")
label_char_pick.grid(row=0, column=0, columnspan=3, pady=10) # POSICIONADO!

label_msg = ctk.CTkLabel(char_pick, text="Selecione seus heróis")
label_msg.grid(row=3, column=0, columnspan=3, pady=10) # POSICIONADO!

# --- Inicialização das imagens (assumindo que os paths estão corretos) ---
try:
    img_guerreiro = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/guerreiro.png")
    ctkimg_guerreiro = ctk.CTkImage(dark_image=img_guerreiro, light_image=img_guerreiro, size=(80, 80))
    
    # ... as outras imagens seguem o mesmo padrão ...
    img_curandeira = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/curandeira.png")
    ctkimg_curandeira = ctk.CTkImage(dark_image = img_curandeira, light_image = img_curandeira, size = (80, 80))

    img_ladino = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/ladino.png")
    ctkimg_ladino = ctk.CTkImage(dark_image = img_ladino, light_image = img_ladino, size = (80, 80))

    img_maga = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/maga.png")
    ctkimg_maga = ctk.CTkImage(dark_image = img_maga, light_image = img_maga, size = (80, 80))

    img_bardo = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/bardo.png")
    ctkimg_bardo = ctk.CTkImage(dark_image = img_bardo, light_image = img_bardo, size = (80, 80))

    img_arqueiro = Image.open("C:/Users/LEO/Desktop/GitHub/Estudos solo/Python/teste batalha rpg/arqueiro.png")
    ctkimg_arqueiro = ctk.CTkImage(dark_image = img_arqueiro, light_image = img_arqueiro, size = (80, 80))

except FileNotFoundError:
    label_msg.configure(text="ERRO: Imagens não encontradas. Verifique os caminhos!")
    # Criar imagens de placeholder se houver erro
    ctkimg_guerreiro = ctk.CTkImage(Image.new('RGB', (80, 80), color = 'red'), size=(80, 80))
    # ... e assim por diante para todos os CTkImages ...


# --- Funções de Seleção CORRIGIDAS ---
# Usamos a técnica de `global` e adicionamos feedback visual e lógica de prevenção de duplicatas

def pick_char(char_name, char_status, button_widget):
    global team_size
    # A variável global precisa ser chamada diretamente, por isso passamos a string
    # E fazemos o acesso via globals()
    char_status_global = globals().get(char_name)

    if char_status_global == True:
        label_msg.configure(text = f"{char_name.capitalize()} já está no time!")
        return

    if team_size >= 4:
        label_msg.configure(text = "Limite de time atingido (4/4)")
        return

    # Se a classe não foi selecionada e o time não está cheio:
    globals()[char_name] = True # Atualiza a variável global (ex: guerreiro = True)
    team_size += 1
    button_widget.configure(state="disabled", fg_color="gray") # Desabilita e muda a cor
    label_msg.configure(text = f"{char_name.capitalize()} selecionado! Time: {team_size}/4")

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


# --- Criação dos Botões (Otimizado) ---
but_char1 = ctk.CTkButton(char_pick, text="Guerreiro", image=ctkimg_guerreiro, compound="top", command=pick_guerreiro)
but_char1.grid(column=0, row=1, pady=5, padx=5, sticky="nsew")

but_char2 = ctk.CTkButton(char_pick, text="Curandeira", image=ctkimg_curandeira, compound="top", command=pick_curandeira)
but_char2.grid(column=1, row=1, pady=5, padx=5, sticky="nsew")

but_char3 = ctk.CTkButton(char_pick, text="Ladino", image=ctkimg_ladino, compound="top", command=pick_ladino)
but_char3.grid(column=2, row=1, pady=5, padx=5, sticky="nsew")

but_char4 = ctk.CTkButton(char_pick, text="Maga", image=ctkimg_maga, compound="top", command=pick_maga)
but_char4.grid(column=0, row=2, pady=5, padx=5, sticky="nsew")

but_char5 = ctk.CTkButton(char_pick, text="Bardo", image=ctkimg_bardo, compound="top", command=pick_bardo)
but_char5.grid(column=1, row=2, pady=5, padx=5, sticky="nsew")

but_char6 = ctk.CTkButton(char_pick, text="Arqueiro", image=ctkimg_arqueiro, compound="top", command=pick_arqueiro)
but_char6.grid(column=2, row=2, pady=5, padx=5, sticky="nsew")


char_pick.mainloop()