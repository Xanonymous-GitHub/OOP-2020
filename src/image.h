#ifndef IMAGE_H
#define IMAGE_H
typedef std::string s;
class Image {
public:
    void setSrc(s src) {
        this->src = src;
    }
    void setPosition(s top, s left) {
        this->top = "top" + top + ";";
        this->left = "left" + left + ";";
    }

    s render() {
        return "<img src=\'" + this->src + "\' " + "style=\'" + this->top + this->left + "\'>";
    }

private:
    s src = "";
    s top = "top:0px;";
    s left = "left:0px;";
};
#endif