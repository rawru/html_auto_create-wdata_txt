#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // no. of lines in name.txt
    int lines = 0;
    string line;
    ifstream sub_line("name.txt");
    while (getline(sub_line, line))
        ++lines;

    // DATA GATHER
    string name[lines], desc[lines], hl[lines];
    string n, d, h;
    int in = 0, id = 0, ih = 0;
    // name
    ifstream names("name.txt");
    while (getline(names, n))
    {
        name[in] = n;
        in++;
    }
    // desc
    ifstream descr("desc.txt");
    while (getline(descr, d))
    {
        desc[id] = d;
        id++;
    }
    // hl
    ifstream highl("hl.txt");
    while (getline(highl, h))
    {
        hl[ih] = h;
        ih++;
    }

    // filename number, change filename_num to whatever is needed
    int filename_num, fnauto = 7;
    string filename;
    // filename_num auto finder
    bool fexist;
    do
    {
        ifstream fname("Page" + to_string(fnauto) + ".html");
        fnauto++;
        if (fname)
            fexist = true;
        else
            fexist = false;
    } while (fexist == true);
    filename_num = fnauto - 1;

    // TEMPLATES
    // this template is currently for: composer content page
    string title, imgpx, hsize, hlhead, hlsize;
    title = "Here's to ";
    imgpx = "250";
    hsize = "1";
    hlhead = "Magnum Opus";
    hlsize = "2";

    // file creation and content insertion
    for (int i = 0; i < lines; i++)
    {
        // filename template
        filename = "Page" + to_string(filename_num) + ".html";
        filename_num++;

        ofstream content(filename);

        content << "<!DOCTYPE html>";
        content << "\n<html>";
        content << "\n    <head>";
        content << "\n        <meta charset=\"utf-8\">";
        content << "\n        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
        content << "\n        <meta charset=\"utf-8\">";
        content << "\n        <meta name=\"Ralph Louie O. Gatan\">";
        content << "\n        <meta section=\"Beryllium\">";
        content << "\n        <title>" + title + name[i] + "!" + "</title>";
        content << "\n    </head>";
        content << "\n    <body>";
        content << "\n        <img src=\"Images/\" height=\"" + imgpx + "px\" alt=\"\">";
        content << "\n        ";
        content << "\n        <h" + hsize + ">" + name[i] + "</h" + hsize + ">";
        // BREADCRUMBS START
        content << "\n        <a href=\"../home.html\">Home</a> >> <a href=\"Page4.html\">Composers</a>";
        content << " >> " + name[i];
        // BREADCRUMBS END
        content << "\n        <hr>";
        content << "\n        <p>" + desc[i] + "</p>";
        content << "\n        </br>";
        content << "\n        <h" + hlsize + ">" + hlhead + "</h" + hlsize + ">";
        content << "\n        <p>" + hl[i] + "</p>";
        content << "\n        </br>";
        content << "\n        <a href=\"Page" + to_string(filename_num - 1) + ".html\">Go back.</a> ";
        content << "<a href=\"Page" + to_string(filename_num + 1) + ".html\">Next.</a>";
        content << "\n        </br>";
        content << "\n        <a href=\"home.html\">Go back home.</a>";
        content << "\n    </body>";
        content << "\n</html>";
    }
}