

void write_2dvector_to_js(std::vector< std::vector<int> > &vec, std::string& outputname);

void write_2dvector_to_file(std::vector< std::vector<int> > &vec, std::string& outputname);

int myPow(int x, int p);

int find_next_pos(std::vector< std::vector<int> > &out_matrix, int *pos);

void substitute(int i, int j, std::vector< std::vector<int> > &in_matrix, std::vector< std::vector<int> > &out_matrix, int *pos);

void printMatrix(std::vector< std::vector<int> > &in_matrix);

bool getMartix(std::vector< std::vector<int> > &vec, std::ifstream& inputfile);

bool getMartix_str_stolb(std::vector< std::vector<int> > &vec, std::ifstream& inputfile);

void addMatrixToFile(std::vector< std::vector<int> > &vec, std::ofstream& outputfile);

void addMatrixToJsFile(std::vector< std::vector<int> > &vec, std::ofstream& outputfile);

void write_miniqs_to_js(std::vector< std::vector<int> > &vec, int n, int uniq_num);

void write_miniqs_to_txt(std::vector< std::vector<int> > &vec, int n, int uniq_num);

bool isItNew(std::vector<int> &minisquare, std::vector< std::vector<int> > &uniq_minisquares, int uniq_num);

int howManyUniqs(std::vector<int> &minisquare, std::vector< std::vector<int> > &all_minisquares, int num);

int getMartices(std::vector< std::vector<int> > &all_minisquares,int n, int m, bool onemx);

void printVector(std::vector< std::vector<int> > &v, int n, int m);

int findNewUniqs(std::vector< std::vector<int> > &uniq_minisquares,std::vector< std::vector<int> > &all_minisquares, int num, int uniq_num);
