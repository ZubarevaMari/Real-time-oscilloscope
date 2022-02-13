program graph;

// подключение библиотеки для работы с виртуальным последовательным портом
uses System.IO.Ports, GraphABC;

const
  freg = 2;
  lengthx = 600;
  lengthy = 600;{Размер окна}

var
  sp{переменная для доступа к порту}: SerialPort;
  s{сообщение}: string;
  x0, y0, x, y, code, i: integer;

begin
  sp := new SerialPort('COM4');
  sp.Open();
  sp.WriteLine('x');
  
  setWindowsize(lengthy, lengthx);
  ClearWindow(clBlack);
  Pen.Color := clGreen;
  Pen.Width := 2;
  repeat
    ClearWindow(clBlack);
    x := 50;
    y0 := 250;
    s := sp.ReadLine();
    Val(s, y, code);
    MoveTo(x, y0 + y);
    while x <=550 do
      begin
         s := sp.ReadLine();
         Val(s, y, code);
         y := y + y0;
         x := x + 15;
         LineTo(x, y);
      end;   
  until false;
  sp.Close();
end.