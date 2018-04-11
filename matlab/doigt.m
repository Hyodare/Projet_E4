function [type_doigt] = doigt(int_sig)
type_doigt = 'signal pas traite' ;

if int_sig == [3, 3, 3]
    type_doigt = 'main totale' ;
elseif int_sig == [3, 3, 1]
    type_doigt = 'pouce' ;
elseif int_sig == [1, 3, 3]
    type_doigt = 'annulaire' ;
elseif int_sig == [1, 3, 1]
    type_doigt = 'theoriquement, majeur'
elseif int_sig == [1, 1, 1]
    type_doigt = 'auriculaire' ;
else
    type_doigt = 'mouvement non reconnu, reessayez' ;
end

type_doigt

end