load('C:\matlab workspace\face recognition\facedatabase\ORL_32_32.mat')
%load('C:\matlab workspace\face recognition\facedatabase\COIL20.mat')
k=2;%���۽�����֤
[d,n]=size(alls);%��ȡ����ά������Ŀ
tabs=tabulate(gnd);
Label=tabs(:,1);%����ǩֵ
Count=tabs(:,2);%��Ӧ������Ŀ
t=[-5:2:10];
b=[0,10.^t];%������ Ϊ0�˻�Ϊ��ͨ���Իع飬�������ΪЭͬ��ʾ��Collaborative Representation��
L1_acc=[];
L2_acc=[];
Linf_acc=[];
Res_acc=[];
for j=1:k
    %���ݼ�����
    test_ind=[];
    lnum=length(Label);
    for i=1:lnum
        tempind=find(gnd==Label(i));
        step=round(Count(i)/k);
        start=(j-1)*step+1;
        jend=min(j*step,Count(i));
        test_ind=[test_ind,tempind(start:jend)];
    end
    %���Լ�
    test=alls(:,test_ind);
    test_label=gnd(:,test_ind);
    %ѵ����
    train_ind=1:n;
    train_ind(test_ind)=[];
    train=alls(:,train_ind);%x'
    train_label=gnd(:,train_ind);
    %���㲻ͬ�������b�µĻع�ϵ��
    coeff={};
    for i=1:length(b)
        coeff{i}=((train'*train+b(i)*eye(length(train_ind))))\train'*test; %w=(x'x+bI)^-1x'y������bΪ�������
    end
    
    for i=1:length(b)
        L1_score=[];%�洢1����������ֵ
        L2_score=[];%�洢2����������ֵ
        Linf_score=[];%�洢�����������ֵ
        res_score=[];%�洢�в������ֵ
        for t=1:length(Label)
            %
            temp_ind=find(train_label==Label(t));
            Mat=coeff{i}(temp_ind,:);
            %�����ع������в����
            XMat=train(:,temp_ind);
            res_score=[res_score;sum((test-XMat*Mat).^2)];
            
            %1������������
            j1scores=sum(abs(Mat));
            L1_score=[L1_score;j1scores];
            
            %2��������
            j2scores=sum(Mat.^2);
            L2_score=[L2_score;j1scores];
            
            %���������
            jinfscores=max(abs(Mat));
            Linf_score=[Linf_score;jinfscores];            
        end
        %������ֵ�������򣬽��з��ࣨ����1����������ֵ����������ྫ��
        [junk, index]=sort(L1_score,'descend');
        predicts=Label(index);
        difs=predicts(1,:)-test_label;
        L1_acc(j,i)=length(find(difs==0))/length(difs);%���ྫ��
        
        %������ֵ�������򣬽��з��ࣨ����2����������ֵ����������ྫ��
        [junk, index]=sort(L2_score,'descend');
        predicts=Label(index);
        difs=predicts(1,:)-test_label;
        L2_acc(j,i)=length(find(difs==0))/length(difs);%���ྫ��
        
        %������ֵ�������򣬽��з��ࣨ���������������ֵ����������ྫ��
        [junk, index]=sort(Linf_score,'descend');
        predicts=Label(index);
        difs=predicts(1,:)-test_label;
        Linf_acc(j,i)=length(find(difs==0))/length(difs);%���ྫ��
        
        %������ֵ�������򣬽��з��ࣨ���òв������ֵ����������ྫ��
        [junk, index]=sort(res_score);
        predicts=Label(index);
        difs=predicts(1,:)-test_label;
        Res_acc(j,i)=length(find(difs==0))/length(difs);%���ྫ��
    end
   
    
end

%%��ͼ���ӻ����
X1=b;
YMatrix1=[mean(L1_acc); mean(Linf_acc);mean(Res_acc)];

% ���� axes
axes1 = axes('Parent',figure,'XMinorTick','on','XScale','log',...
    'FontWeight','bold',...
    'FontSize',16);
box(axes1,'on');
hold(axes1,'on');

% ���� ylabel
ylabel({'Accuracy'});

% ���� xlabel
xlabel({'b'});

% ʹ�� semilogx �ľ������봴������
semilogx1 = semilogx(X1,YMatrix1,'LineWidth',4,'Parent',axes1,...
    'MarkerSize',8);
set(semilogx1(1),'DisplayName','CRC(L1-Score)','MarkerEdgeColor',[1 0 0],...
    'Marker','square',...
    'Color',[1 0 0],...
    'MarkerSize',6);
set(semilogx1(2),'DisplayName','CRC(L\infty-score)',...
    'MarkerEdgeColor',[0 0.498039215803146 0],...
    'Marker','o',...
    'LineStyle',':',...
    'Color',[0 0.498039215803146 0]);
set(semilogx1(3),'DisplayName','CRC(Residual)','MarkerEdgeColor',[0 0 1],...
    'Marker','^',...
    'LineStyle','--',...
    'Color',[0 0 1]);

% ���� legend
legend1 = legend(axes1,'show');
set(legend1,...
    'Position',[0.155071490815253 0.167055555315263 0.205942618523221 0.106385983647335],...
    'FontSize',14.4);


% semilogx(b,mean(L1_acc),'r-*')
% hold on
% %semilogx(b,mean(L2_acc),'b:<') hold on
% semilogx(b,mean(Linf_acc),'g:o')
% hold on
% semilogx(b,mean(Res_acc),'c--p')






