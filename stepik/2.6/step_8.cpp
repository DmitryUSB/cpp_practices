char *resize(const char *str, unsigned size, unsigned new_size)
{
    char * tmp_str = new char[new_size];
    for (unsigned i = 0; i < new_size; i++) {
        tmp_str[i] = str[i];
    }
    delete [] str;
    str = 0;
    return tmp_str;
}
