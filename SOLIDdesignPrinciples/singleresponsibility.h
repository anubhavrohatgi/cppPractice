#ifndef SINGLERESPONSIBILITY_H
#define SINGLERESPONSIBILITY_H


#include <iostream>
#include <vector>
#include <fstream>

/**
 * @brief ifFileExists Checks if the file exisits
 * @param fname Input filename
 * @return
 */
inline bool ifFileExists(const std::string& fname)
{
    std::ifstream f(fname.c_str());
    return f.good();
}

//---------------------------------------------------------

/*
 * The class should have single responsibility.
 * It should have only one reason to change.
 * Do one thing, do it best
 * By abstracting the functionality that handles the saving
 * and loading, we no longer violate the single responsibility principle.
 */


/**
 * @brief The notes class has a single responsibility of
 * adding notes
 */
class notes {
public:
    explicit notes() {
        //ctor
    }

    void addnote(const std::string& data) {
        this->data.append(data);        
    }

    void setTitle(const std::string& data) {
        this->title = data;
    }

    std::string getData() const {
        return data;
    }

    std::string getTitle() const {
        return title;
    }

private:
    std::string title;
    std::string data;

};


class storage {
public:
    static bool save(const notes& nts, const std::string& fname) {
            std::ofstream file;
            file.open(fname);
            file<<nts.getTitle()<<std::endl;
            file<<nts.getData()<<std::endl;
            file.close();
            return true;
    }

    static bool load(notes& nts, const std::string& fname) {
        if(ifFileExists(fname)){
                std::ifstream file;
                file.open(fname);
                std::string str1,str2;
                std::getline(file,str1);
                std::getline(file,str2);
                file.close();
                nts.setTitle(str1);
                nts.addnote(str2);
                return true;
        } else {
            return  false;
        }
    }
};


#endif // SINGLERESPONSIBILITY_H
