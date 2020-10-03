program tc04;
var i,j,k:integer;
begin
    i:=1;j:=1;k:=1;
    while (i<11) do
    begin
        while (j<12) do
        begin
            while (k<13) do
                begin
                    k:=k+3
                end;
            j:=j+2
            i:=4;
        end;
    i:=i+1;
    end;
end.