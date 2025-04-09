#include <iostream>
#include <string>

//using namespace std;
using std::cout;
using std::endl;
using std::string;

class Image {
private:
    string name;
public:
    Image() : name() {}
    string get_image_name() const {  
        return name; 
    }
    void set_image_name(const string& tmp) {
        name = tmp;
    }
};

class Image_Storage {
public:
    virtual void Save(const Image& image) = 0;
};

class Cloud_Storage : public Image_Storage {
public:
    void Save(const Image& image) override {
        cout << endl << "Image " << image.get_image_name() << " save in cloud" << endl;
    }
};

class Image_Loader {
public:
    virtual Image Load(const string& imageName) = 0;
};

class Http_Loader : public Image_Loader {
public:
    Image Load(const string& zapros) override {
        cout << endl << "Image " << zapros << " load with http" << endl;
        Image tmp; tmp.set_image_name(zapros);
        return tmp;
    }
};

class Duplicate_Remover {
public:
    int Delete_Duplicates() {
        int deletedCount = 100; 
        return deletedCount;
    }
};

class User_Account {
private:
    string username;
    string profileImage;
public:
    User_Account() : username(), profileImage(){}
    void set_username(const string& name) {
        username = name;
    }
    void set_profile_image(const string& imageName) {
        profileImage = imageName;
    }
    string get_username() const { 
        return username; 
    }
    string get_profile_image() const { 
        return profileImage; 
    }
};

class Account_ImageSetter {
public:
    void Image_in_Account(User_Account& account, const string& imageName) {
        account.set_profile_image(imageName);
        cout << endl << "Image " << imageName << " set in profile image " << account.get_username() << endl;
    }
};

int main() {
    Image image;                              image.set_image_name("name1");
    User_Account user;                        user.set_username("user1"); 
    Cloud_Storage cloudSaver;                 cloudSaver.Save(image);
    Http_Loader galleryLoader;                galleryLoader.Load("http://hello_world!/");
    
    Duplicate_Remover remover;
    int deleted_duplicates = remover.Delete_Duplicates();
    cout << endl << "Duplicates remove: " <<  deleted_duplicates << endl;
    
    Image image_for_profil;              image_for_profil.set_image_name("name2");
    Account_ImageSetter imageSetter;
    imageSetter.Image_in_Account(user, image_for_profil.get_image_name());
    cout << endl << "Name profile image: "<<  user.get_profile_image() << endl << endl;

    return 0;
}
