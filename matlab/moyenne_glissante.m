function [moy_glissante] = moyenne_glissante(signal, temps, dt)

Te = (temps(2)-temps(1)) ;
Fe = 1/Te ;
Ne = fix(dt * Fe) ;
B = 1/Ne * (ones(1,Ne)) ;
A = 1 ;

signal = filter(B, A, signal) ;
[SIGNAL,f] = pwelch(signal, [], [], [], Fe) ;

moy_glissante = signal ;

end