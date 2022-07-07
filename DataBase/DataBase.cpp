class DataBase
{
  public:
	std::unordered_map<std::string, std::string> data;
	void insert(std::string a1, std::string a2);
	std::string get(std::string a1);
	void save(std::string a1);
	void load(std::string a1);
};
void DataBase::save(std::string fname)
{
	std::ofstream file("db/" + fname + ".db");
	file << "token\n" + get("token") + "\nid\n" + get("id")+"\nname\n"+get("name")+"\nname_set\n"+get("name_set");
	file.close();
}
void DataBase::load(std::string fname)
{
	std::ifstream file("db/" + fname + ".db");
	std::string k, v;
	while (!file.eof())
	{
		file >> k;
		file >> v;
		insert(k, v);
	}
	file.close();
}
void DataBase::insert(std::string item, std::string value)
{
	data[item] = value;
}
std::string DataBase::get(std::string item)
{
	return data[item];
}
