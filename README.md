# Obiektowe cpp
Visual Studio Community 2019 16.7.7

## Lista klas

### Equipment
* public:
  * **Equipment()** - pusty konstruktor, inicjuje domyślne wartości pól
  * **T getCurrentFrequency()** - zwraca wartość pola currentFrequency
  * **bool setCurrentFrequency(T f)** - ustawia pole currentFrequency i zwraca true jeżeli operacja się powiodła
  * **T getVoltage()** - zwraca pole voltage
  * **bool setVoltage(T v)** - ustawia pole voltage i zwraca true jeżeli operacja się powiodła
  * **virtual std::string about()** - przedstawia pola klasy (używane w komendzie SHOW)
  * **virtual void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
  * **virtual std::vector<std::string> exportData()** - exportuje pola obiektu do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
  * **virtual std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (używane w poleceniu MDO)
* protected:
  * **T voltage** - wartość napięcia zasilajacego urządzenie
  * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* private:
  * **T currentFrequency** - wartość częstotliwości prądu zasilajacego urządzenie


### Audio
* protected
    * **double power** - moc audio urządzenia
* private
    * **double frequency_start** - początek obsługiwanej częstotliwości audio
    * **double frequency_end** - koniec obsługiwanej częstotliwości audio
    * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* public
    * **Audio()** - pusty konstruktor, inicjuje domyślne wartości pól
    * **Audio(double pwr, double f_start, double f_end)** - konstruktor ustawiający wartości pól
    * **virtual std::string about()** - przedstawia pola klasy, wraz z polami klas nadrzędnych (używane w komendzie SHOW)
    * **virtual void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach wraz z polami klas nadrzędnych (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
    * **virtual std::vector<std::string> exportData()** - exportuje pola obiektu (wraz z plami klas nadrzędnych) do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
    * **virtual std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (wraz z polami klas nadrzędnych) (używane w poleceniu MDO)

### Visual
* private:
  * **std::array<int, 2> resolution = { 640, 480 }** - tablica z rozdzielczością [pozioma, pionowa]
* protected:
  * **std::string mode** - tryb obrazu (PAL/SECAM/NTSC)
  * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* public:
  * **Visual()** - pusty konstruktor, inicjuje domyślne wartości pól
  * **Visual(std::string m, std::array<int, 2> res)** - konstruktor ustawiający wartości pól
  * **bool setMode(std::string m)** - ustawia tryb obrazu, zwraca true jeżeli operacja się powiodła
  * **virtual std::string about()** - przedstawia pola klasy, wraz z polami klas nadrzędnych (używane w komendzie SHOW)
  * **virtual void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach wraz z polami klas nadrzędnych (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
  * **virtual std::vector<std::string> exportData()** - exportuje pola obiektu (wraz z plami klas nadrzędnych) do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
  * **virtual std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (wraz z polami klas nadrzędnych) (używane w poleceniu MDO)

### TV
* private:
    * **int screenSize** - rozmiar ekranu w calach
* protected:
    * **double screenRatio** - proporcje ekranu
    * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* public:
    * **TV()** - pusty konstruktor, inicjuje domyślne wartości pól
    * **TV(int size, double ratio)** - konstruktor ustawiający wartości pól
    * **double getScreenRatio()** - zwraca wartość pola screenRatio
    * **bool setScreenRatio(double ratio)** - ustawia wartośc pola screenRatio, zwraca true jeżeli operacja się powiodła
    * **int getScreenSize()** - zwraca wartośc pola screenSize
    * **bool setScreenSize(int size)** - ustawia wartośc pola screenRatio, zwraca true jeżeli operacja się powiodła
    * **virtual std::string about()** - przedstawia pola klasy, wraz z polami klas nadrzędnych (używane w komendzie SHOW)
    * **virtual void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach wraz z polami klas nadrzędnych (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
    * **virtual std::vector<std::string> exportData()** - exportuje pola obiektu (wraz z plami klas nadrzędnych) do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
    * **virtual std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (wraz z polami klas nadrzędnych) (używane w poleceniu MDO)

### TapeRecorder
* protected:
  * **double speed** - prędkość magnetowidu w cm/s
* private:
  * **int paths** - liczba ścieżek
  * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* public:
  * **TapeRecorder()** - pusty konstruktor, inicjuje domyślne wartości pól
  * **TapeRecorder(double power, double f_start, double f_end, double spd, int pths)** - konstruktor ustawiający wartości pól
  * **static Equipment<double>* create(std::vector<std::string>)** - metoda statyczna tworząca nowy obiekt z wartościami pól podanymi w postaci wektora stringów
  * **std::string about()** - przedstawia pola klasy, wraz z polami klas nadrzędnych (używane w komendzie SHOW)
  * **void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach wraz z polami klas nadrzędnych (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
  * **std::vector<std::string> exportData()** - exportuje pola obiektu (wraz z plami klas nadrzędnych) do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
  * **std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (wraz z polami klas nadrzędnych) (używane w poleceniu MDO)

### CDPlayer
* private:
  * **bool remoteIncluded** - dołączony pilot
* protected:
  * **std::string displayColor** - kolor wyświetlacza (blue/red/green/dark)
  * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* public:
   * **bool isRemoteIncluded()** - zwraca pole remoteIncluded
   * **bool setDisplayColor(std::string color)** - ustawia kolor wyświetlacza
   * **std::string getDisplayColor()** - zwraca kolor wyświetlacza
   * **CDPlayer()** - pusty konstruktor, inicjuje domyślne wartości pól
   * **CDPlayer(double power, double f_start, double f_end, bool remoteIncluded, std::string displayColor)** - konstruktor ustawiający wartości pól
   * **static Equipment<double>* create(std::vector<std::string>)** - metoda statyczna tworząca nowy obiekt z wartościami pól podanymi w postaci wektora stringów
   * **std::string about()** - przedstawia pola klasy, wraz z polami klas nadrzędnych (używane w komendzie SHOW)
   * **void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach wraz z polami klas nadrzędnych (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
   * **std::vector<std::string> exportData()** - exportuje pola obiektu (wraz z plami klas nadrzędnych) do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
   * **std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (wraz z polami klas nadrzędnych) (używane w poleceniu MDO)

### Radio
* private:
  * **int memorySize** - wielkość pamięci stacji radiowych
* protected:
  * **int speakers** - liczba głośników
  * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* public:
  * **bool setMemorySize(int m)** - ustawienie wielkości pamieci (zwraca true jeżeli operacja się powiodła)
  * **bool setSpeakers(int s)** - ustawienie liczby głośników (zwraca true jeżeli operacja się powiodła)
  * **int getMemorySize()** - zwraca wielkość pamięci
  * **int getSpeakers()** - zwraca liczbę głośników
  * **Radio()** - konstruktor ustawiający domyślne wartości pól
  * **Radio(int m, int s)** - konstruktor ustawiający wartości pól
  * **static Equipment<double>* create(std::vector<std::string>)** - metoda statyczna tworząca nowy obiekt z wartościami pól podanymi w postaci wektora stringów
  * **std::string about()** - przedstawia pola klasy, wraz z polami klas nadrzędnych (używane w komendzie SHOW)
  * **void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach wraz z polami klas nadrzędnych (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
  * **std::vector<std::string> exportData()** - exportuje pola obiektu (wraz z plami klas nadrzędnych) do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
  * **std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (wraz z polami klas nadrzędnych) (używane w poleceniu MDO)
  * **int operator[](int x)** - operator zwracający wielkość pamięci, stworzony na siłę, nie miałem pomysłu na wykorzystanie go

### Camera
* private:
  * **static const double DEFAULT_FOCAL_LENGTH** - domyślna wartość pola focalLength
  * **static const double DEFAULT_OPTICAL_ZOOM** - domyślna wartość pola opticalZoom
  * **double focalLength** - ogniskowa soczewki
* protected:
  * **double opticalZoom** - zoom optyczny
  * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* public:
  * **double getFocalLength()** - zwraca pole focalLength
  * **double getOpticalZoom()** - zwraca pole opticalZoom
  * **bool setFocalLength(double f)** - ustawia pole focalLength (zwraca true jeżeli operacja się powiodła)
  * **bool setOpticalZoom(double z)** - ustawia pole opticalZoom (zwraca true jeżeli operacja się powiodła)
  * **Camera()** - pusty konstruktor, inicjuje domyślne wartości pól
  * **Camera(std::string mode, std::array<int, 2> res, double f, double z)** - konstruktor ustawiający wartości pól
  * **static Equipment<double>* create(std::vector<std::string>)** - metoda statyczna tworząca nowy obiekt z wartościami pól podanymi w postaci wektora stringów
  * **std::string about()** - przedstawia pola klasy, wraz z polami klas nadrzędnych (używane w komendzie SHOW)
  * **void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach wraz z polami klas nadrzędnych (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
  * **std::vector<std::string> exportData()** - exportuje pola obiektu (wraz z plami klas nadrzędnych) do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
  * **std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (wraz z polami klas nadrzędnych) (używane w poleceniu MDO)

### PortableTV
* private:
  * **double weight** - waga telewizora
* protected:
  * **bool portableAntenna** - wyposażenie w wbudowaną antenę
  * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* public:
  * **double getWeight()** - zwraca wagę telewizora
  * **bool setWeight(double w)** - ustawia wagę telewizora (zwraca true jeżeli operacja się powiedzie)
  * **bool isAntennaPortable()** - zwraca czy telewizor jest wyposażony w wbudowaną antenę
  * **bool setPortableAntenna(bool a)** - ustawia wbudowaną antenę
  * **PortableTV()** - konstruktor inicjujący domyślne parametry
  * **PortableTV(int size, double ratio, double w, double a)** - konstruktor ustawiający wartości pól
  * **static Equipment<double>* create(std::vector<std::string>)** - metoda statyczna tworząca nowy obiekt z wartościami pól podanymi w postaci wektora stringów
  * **std::string about()** - przedstawia pola klasy, wraz z polami klas nadrzędnych (używane w komendzie SHOW)
  * **void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach wraz z polami klas nadrzędnych (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
  * **std::vector<std::string> exportData()** - exportuje pola obiektu (wraz z plami klas nadrzędnych) do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
  * **std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (wraz z polami klas nadrzędnych) (używane w poleceniu MDO)

### StationaryTV
* private:
    * **bool smart = false** - czy telewizor zawiera SMART
* protected:
    * **bool wifi = false** - czy telewizor obsługuje Wi-Fi
    * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* public:
    * **bool setSmart(bool s)** - ustawia obsługę SMART
    * **bool setWifi(bool w)** - ustawia obsługę Wi-Fi
    * **bool haveWifi()** - zwraca czy telewizor obsługuje Wi-Fi
    * **bool isSmart()** - zwraca czy telewizor obsługuje SMART
    * **StationaryTV()** - konstruktor inicjujący domyślne parametry
    * **StationaryTV(int size, double r, bool s, bool w)** - konstruktor ustawiający wartości pól
    * **static Equipment<double>* create(std::vector<std::string>)** - metoda statyczna tworząca nowy obiekt z wartościami pól podanymi w postaci wektora stringów
    * **std::string about()** - przedstawia pola klasy, wraz z polami klas nadrzędnych (używane w komendzie SHOW)
    * **void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach wraz z polami klas nadrzędnych (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
    * **std::vector<std::string> exportData()** - exportuje pola obiektu (wraz z plami klas nadrzędnych) do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
    * **std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (wraz z polami klas nadrzędnych) (używane w poleceniu MDO)
### VideocasetteRecorder
* private:
  * **static const int DEFAULT_HEADS_NUMBER** - domyślna wartość pola numberOfHeads
  * **static const bool DEFAULT_AUTO_CLEANING_HEADS** - domyślna wartość pola autoCleaningHeads
  * **bool autoCleaningHeads** - samoczyszczące sie głowice
* protected:
  * **int numberOfHeads** - liczba głowic
  * **std::vector<std::string> attribs** - wektor zawierajacy nazwy pól zwracane przez getAttribNames()
* public:
  * **int getNumberOfHeads()** - zwraca liczbę głowic
  * **bool setNumberOfHeads(int n)** - ustawia liczbę głowic
  * **bool haveAutocleaningHeads()** - sprawdza czy urządzenie wyposażone jest w samoczyszczące się głowice
  * **bool setAutocleaningHeads(bool ach)** - ustawia autoczyszczące się głowice
  * **VideocasetteRecorder()** - konstruktor inicjujący domyślne parametry
  * **VideocasetteRecorder(std::string mode, std::array <int, 2> res, int n, bool ach)** - konstruktor ustawiający wartości pól
  * **static Equipment<double>* create(std::vector<std::string>)** - metoda statyczna tworząca nowy obiekt z wartościami pól podanymi w postaci wektora stringów
  * **std::string about()** - przedstawia pola klasy, wraz z polami klas nadrzędnych (używane w komendzie SHOW)
  * **void importData(std::vector<std::string> v)** - ustawia pola obiektu wedle wartości podanych w argumentach wraz z polami klas nadrzędnych (używane przy importowaniu danych z pliku, a także w poleceniu MDO)
  * **std::vector<std::string> exportData()** - exportuje pola obiektu (wraz z plami klas nadrzędnych) do wektora rozumianego przez metode importData (używane przy exportowaniu danych do pliku, a także w poleceniu MDO)
  * **std::vector<std::string> getAttribNames()** - zwraca przyjazne użytkownikowi nazwy pól (wraz z polami klas nadrzędnych) (używane w poleceniu MDO)


## Klasy pomocnicze
### Shell
* public:
  * **void run()** - uruchamia shella dla użytkownika
  * **typedef std::vector<std::string> arg_array** - definujemy typ wykorzystywyany jako lista argumentów przekazywanych do komend
* protected:
  * **typedef std::string(Shell::* cmd_ptr)(arg_array)** - definujemy typ wskaźnika na metodę będącą odpowiednikiem komendy wpisanej przez użytkownika
  * **Storage storage** - klasa obsługująca przechowywanie obiektów
  * **std::string getCommandPrompt()** - zwraca znak zachęty w shellu
  * **std::string runCommand(std::vector<std::string> args)** - uruchamia odpowiednią komende na podstawie argumentów podanych (pierwszy element to nazwa komendy)
  * **std::vector<std::string> inputCommand()** - metoda obsługująca wpisanie komendy przez użytkownika i zwracająca arg_array
  * **std::vector<std::string> splitCommand(std::string cmd)** - zamienia stringa rozdzielonego spacjami na vector stringów
  * **cmd_ptr getCommand(std::string cmd)** - zwraca wskaźnik na odpowiednią metode wywołaną przez użytkownika
  * **std::string _tree(arg_array args)** - komenda usera, wyświetla drzewo klas | `TREE`
  * **std::string _cd(arg_array args)** - komenda usera, zmiana węzła | `CD Radio`
  * **std::string _makeObject(arg_array args)** - komenda usera, tworzy obiekt (przyjmuje opcjonalne argumenty będące wartościami pól (w takiej kolejności jak importData/exportData)) | `MO obiekt1`
  * **std::string _modifyObject(arg_array args)** - komenda usera, modyfikuje obiekt | `MDO obiekt1`
  * **std::string _dir(arg_array args)** - komenda usera, listuje obiekty klas | `DIR`
  * **std::string _show(arg_array args)** - komenda usera, pokazuje pola obiektu | `SHOW obiekt1`
  * **std::string _save(arg_array args)** - komenda usera, exportuje stan bazy danych do pliku | `SAVE baza.iod`
  * **std::string _read(arg_array args)** - komenda usera, importuje stan bazy danych z pliku | `READ baza.iod`
  * **std::string _deleteObject(arg_array args)** - komenda usera, usuwa obiekt | `DO obiekt1`
  * **std::string _exit(arg_array args)** - wyjście | `EXIT`

### Storage
* protected:
  * **typedef Equipment<double>*(*class_fctry)(std::vector<std::string>)** - typ definujący wskaźnik na statyczną metodę create (występującą w klasach liściach) tworzącą obiekty danej klasy z wartościami pól  vektorze
  * **struct Node {** - struktura reprezentująca węzeł w grafie klas
    * **Node* parent;** - wskaźnik na węzeł klasy nadrzędnej
    * **std::string name;** - nazwa klasy (wyświetlana użytkownikowi)
    * **std::map<std::string, Equipment<double>*> objects;** - mapa obiektów klasy
    * **std::vector<Node*> children;** - klasy dziedziczące
    * **class_fctry create = nullptr;** - wskaźnik na statyczną metodę tworzącą obiekt klasy
  * } Node
  * **std::string currentNode** - pole zawierające nazwę obecnie używanej klasy (wybranej przez polecenie CD)
  * **std::string rootNode** - korzeń grafu klas
  * **static std::string join(std::vector<std::string> v)** - pomocnicza metoda łącząca vektor stringów w jednego stringa rozdzielonego spacją
* public:
  * **Storage()** - konstruktor inicjujący graf klas, szukający rootNode i ustawia currentNode
  * **bool changeNode(std::string nm)** - zmienia obecnie wykorzystywany node
  * **std::string getCurrentNode()** - zwraca obecnie wykorzystywany node
  * **std::string tree(std::string base = "", bool includeObjects = false)** - startowa metoda uruchamiajaca reccurringTree
  * **std::map<std::string, struct Node> classes** - mapa przechowująca graf klas
  * **std::map<std::string, Equipment<double>*>* getObjects()** - zwraca obiekty obecnie wykorzystywanej klasy
  * **std::string dump()** - exportuje bazę w postaci listy komend
* private:
  * **std::string reccuringTree(struct Node* node, bool includeObjects = false, int level = 0)** - metoda wykorzystywana w metodzie tree(), przechodzi przez drzewo klas od podanej klasy startowej i wyświetla listę tych klas (oraz opcjonalnie obiektów)

## Środowisko
```
Microsoft Visual Studio Community 2019
Wersja 16.7.7
VisualStudio.16.Release/16.7.7+30621.155
Microsoft .NET Framework
Wersja 4.8.03752

Zainstalowana wersja: Community

Visual C++ 2019   00435-60000-00000-AA955
Microsoft Visual C++ 2019

ASP.NET and Web Tools 2019   16.7.532.28833
ASP.NET and Web Tools 2019

Kreatory programu Microsoft Visual C++   1.0
Kreatory programu Microsoft Visual C++

Menedżer pakietów NuGet   5.7.0
Menedżer pakietów NuGet w programie Visual Studio. Więcej informacji na temat narzędzia NuGet można znaleźć na stronie https://docs.nuget.org/

Microsoft JVM Debugger   1.0
Provides support for connecting the Visual Studio debugger to JDWP compatible Java Virtual Machines

Microsoft MI-Based Debugger   1.0
Provides support for connecting Visual Studio to MI compatible debuggers

Narzędzia języka C#   3.7.0-6.20514.1+600c0dadd199296df3ed07dfabdc014563a77f7c
Składniki języka C# używane w środowisku IDE. Zależnie od typu projektu i jego ustawień może być używana inna wersja kompilatora.

Narzędzia języka Visual Basic   3.7.0-6.20514.1+600c0dadd199296df3ed07dfabdc014563a77f7c
Składniki języka Visual Basic używane w środowisku IDE. Zależnie od typu projektu i jego ustawień może być używana inna wersja kompilatora.

Pakiet hosta adaptera debugowania programu Visual Studio Code   1.0
Warstwa międzyoperacyjności na potrzeby hostowania adapterów debugowania programu Visual Studio Code w programie Visual Studio

Pakiet VC programu Microsoft Visual Studio   1.0
Pakiet VC programu Microsoft Visual Studio

ProjectServicesPackage Extension   1.0
ProjectServicesPackage Visual Studio Extension Detailed Info

Rozszerzenie IntelliCode   1.0
Szczegółowe informacje dotyczące rozszerzenia IntelliCode programu Visual Studio

Test Adapter for Boost.Test   1.0
Enables Visual Studio's testing tools with unit tests written for Boost.Test.  The use terms and Third Party Notices are available in the extension installation directory.

Test Adapter for Google Test   1.0
Udostępnia w narzędziach do testowania w programie Visual Studio testy jednostkowe napisane dla platformy Google Test. Warunki korzystania i uwagi podmiotu trzeciego można znaleźć w katalogu instalacyjnym rozszerzenia.

Visual Studio Tools for CMake   1.0
Visual Studio Tools for CMake
```
