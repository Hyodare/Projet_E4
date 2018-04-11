function [int_sig] = intensite_signal(signal1, signal2, signal3)

delta = [] ;
delta(:,1) = max(signal1) - min(signal1) ;
delta(:,2) = max(signal2) - min(signal2) ;
delta(:,3) = max(signal3) - min(signal3) ;

% delta

int_sig = [] ;

for i = 1:length(delta)
    if delta(:,i) < 0.6 & delta(:,i) > 0.10
        int_sig(:,i) = 1 ; % signal faible
    elseif delta(:,i) > 0.6
        int_sig(:,i) = 3 ; % signal fort
    else
        int_sig(:,i) = 0 ; % bruit ?
    end
end

end