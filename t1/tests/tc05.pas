program tc05;
var i,j,k:integer;
begin
    i:=1;j:=1;k:=1;
    if (i<11)
    then begin
        i:=i+5
    end;
    if not(j<=k)
    then begin
        if (i + j)>5 then i:=0
    end
    else begin
        if j>0 then j:=0
            else j:=1000
    end;
end.