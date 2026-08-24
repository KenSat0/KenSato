#include <iostream>
#include <string>
#include <vector>

class playlist;
class musica;

class musica{
    public:
        std::string name;
        std::string artist;
        int duration;
        int id;
        playlist *ref;

        void SetName(std::string name){
            this->name = name;
        }
        void SetArtist(std::string artist){
            this->artist = artist;
        }
        void SetDuration(int duration){
            this->duration = duration;
        }
        void SetId(int id){
            this->id = id;
        }
        void SetPLaylist(playlist *p){
            this->ref = p;
        }
        musica(std::string name, std::string artist, int duration, int id, playlist *p){
            SetName(name);
            SetArtist(artist);
            SetDuration(duration);
            SetId(id);
            SetPLaylist(p);
        }
        std::string GetName(){
            return(this->name);
        }
        std::string GetArtist(){
            return(this->artist);
        }
        int GetDuration(){
            return duration;
        }
        int GetId(){
            return id;
        }
        void ShowDetails(){
            std::cout << "Título: " << this->name << '\n';
            std::cout << "Artista/Banda: " << this->artist << '\n';
            std::cout << "Duração: " << this->duration << '\n';
            std::cout << "ID: " << this->id << '\n';
        }
};

class playlist{
    public:
        std::string name;
        int size;
        int playlist_id;
        std::vector<musica*> musicas;

    void SetName(std::string name){
        this->name = name;
    }
    void SetSize(int size){
        this->size = size;
    }
    void SetId(int playlist_id){
        this->playlist_id = playlist_id;
    }
    playlist(std::string name, int size, int playlist_id){
        SetName(name);
        SetSize(size);
        SetId(playlist_id);
    }
}