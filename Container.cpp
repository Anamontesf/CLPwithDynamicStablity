#pragma warning (disable: 4786)

#include "Container.h"


//Para que pueda tener las piezas información del contenedor
CONTAINER* SPACE::m_Container=NULL;
CONTAINER* PIECE::m_Container=NULL;
CONTAINER* BLOQUE::m_Container=NULL;
CONTAINER* CONFIGURACAO::m_Container=NULL;
//Orden por volumen
//Si tienen el mismo valor la más grande
bool PIECE::operator < ( const PIECE& p2)
{
	//Si no son restringidas
	if (m_Volumen==p2.m_Volumen)
	{
		if ((m_x+m_y+m_z)==(p2.m_x+p2.m_y+p2.m_z))
		{
		//Por la eficiencia
		if (m_x==p2.m_x)
		{
			if (m_y==p2.m_y)
			{
				return (m_z>p2.m_z);
			}
			else	
			return (m_y>p2.m_y);
			//(p1.largo*p1.ancho)>(p2.largo*p2.ancho);
		}
		else
			//Por el área de lo que puedo poner
		return (m_x>p2.m_x);//(p1.max*p1.largo*p1.ancho)>(p2.max*p2.largo*p2.ancho);
		}
		else
			return ((m_x+m_y+m_z)<(p2.m_x+p2.m_y+p2.m_z));
	}
	else
		return (m_Volumen>p2.m_Volumen);

}
bool CONFIGURACAO::operator<(const CONFIGURACAO &p2) 
{
	if (m_Container->Get_Tipo_Gravedad()==0)
	{
		//Si no son restringidas
		if ((m_z1)==(p2.m_z1))
		{
			//Por la eficiencia
			if (m_x1==p2.m_x1)
			{
				return (m_y1<p2.m_y1);
			}
			else
				//Por el área
			return (m_x1<p2.m_x1);
		}
		else
			return (m_z1<p2.m_z1);
	}
	if (m_Container->Get_Tipo_Gravedad()==1)
	{
		//Si no son restringidas
		if ((m_x1)==(p2.m_x1))
		{
			//Por la eficiencia
			if (m_z1==p2.m_z1)
			{
				return (m_y1<p2.m_y1);
			}
			else
				//Por el área
			return (m_z1<p2.m_z1);
		}
		else
			return (m_x1<p2.m_x1);
	}
	if (m_Container->Get_Tipo_Gravedad()==2)
	{
		//Si no son restringidas
		if ((m_y1)==(p2.m_y1))
		{
			//Por la eficiencia
			if (m_x1==p2.m_x1)
			{
				return (m_z1<p2.m_z1);
			}
			else
				//Por el área
			return (m_x1<p2.m_x1);
		}
		else
			return (m_y1<p2.m_y1);
	}
	//Para dibujar
	if (m_Container->Get_Tipo_Gravedad()==3)
	{
		//Si no son restringidas
		if ((m_x1)==(p2.m_x1))
		{
			//Por la eficiencia
			if (m_z1==p2.m_z1)
			{
				return (m_y1<p2.m_y1);
			}
			else
				//Por el área
			return (m_z1<p2.m_z1);
		}
		else
			return (m_x1<p2.m_x1);
	}
}

ORIG::ORIG()
{
//	std::vector<short int> vec(3);
//	m_orig=vec;
	
}

ORIG::ORIG(int a,int b, int c)
{
//	std::vector<short int> vec(3);
//	m_orig=vec;
//	m_orig.push_back(0);
//	m_orig.push_back(0);
//	m_orig.push_back(0);

	if (a>=__max(b,c))
	{
		m_tercero=a;
		if (b>=c)
		{
			m_segundo=b;
			m_primero=c;
		}
		else
		{
			m_primero=b;
			m_segundo=c;

		}
	}
	else
	{
		if (b>=c)
		{
			m_tercero=b;
			if (c>=a)
			{
				m_segundo=c;
				m_primero=a;
			}
			else
			{
				m_segundo=a;
				m_primero=c;

			}
		}
		else
		{
			m_tercero=c;
			if (b>=a)
			{
				m_segundo=b;
				m_primero=a;
			}
			else
			{
				m_segundo=a;
				m_primero=b;

			}
		}
	}
}
void SPACE::Cambiar(ORIG &orig,int a,int b,int c)
{
	
	if (a>=__max(b,c))
	{
		orig.SetTercero(a);
		if (b>=c)
		{
			orig.SetSegundo(b);
			orig.SetPrimero(c);
		}
		else
		{
			orig.SetPrimero(b);
			orig.SetSegundo(c);

		}
	}
	else
	{
		if (b>=c)
		{
			orig.SetTercero(b);
			if (c>=a)
			{
				orig.SetSegundo(c);
				orig.SetPrimero(a);
			}
			else
			{
				orig.SetSegundo(a);
				orig.SetPrimero(c);

			}
		}
		else
		{
			orig.SetTercero(c);
			if (b>=a)
			{
				orig.SetSegundo(b);
				orig.SetPrimero(a);
			}
			else
			{
				orig.SetSegundo(a);
				orig.SetPrimero(b);

			}
		}
	}
}
void CONFIGURACAO::Cambiar(ORIG &orig,int a,int b,int c)
{
	if (a>=__max(b,c))
	{
		orig.SetTercero(a);
		if (b>=c)
		{
			orig.SetSegundo(b);
			orig.SetPrimero(c);
		}
		else
		{
			orig.SetPrimero(b);
			orig.SetSegundo(c);

		}
	}
	else
	{
		if (b>=c)
		{
			orig.SetTercero(b);
			if (c>=a)
			{
				orig.SetSegundo(c);
				orig.SetPrimero(a);
			}
			else
			{
				orig.SetSegundo(a);
				orig.SetPrimero(c);

			}
		}
		else
		{
			orig.SetTercero(c);
			if (b>=a)
			{
				orig.SetSegundo(b);
				orig.SetPrimero(a);
			}
			else
			{
				orig.SetSegundo(a);
				orig.SetPrimero(b);

			}
		}
	}
}
void CONTAINER::InicializarVariables()
{
	m_total_volumen_ocupado=0;
	//m_total_costo_ocupado=0;
	m_Dibujar=false;
	m_max_total_volumen_ocupado=0;
	//m_max_total_costo_ocupado=0;
	m_objetivo_vol=true;
	m_tipo_mixto=false;

}
CONTAINER::CONTAINER(char *nombre,int caso,int opcion)
{
	LeerDatosContainer(nombre,opcion);
	//Ordeno las piezas por volumen
//	std::sort(m_Pieces.begin(),m_Pieces.end());
	//Ahora pongo los numeritos
	int id=0;
	std::vector< PIECE > ::iterator it;
	for (it=m_Pieces.begin(),id=0;it!=m_Pieces.end();it++,id++)
	{
		(*it).Set_Id(id);
	}
	m_total_volumen_ocupado=0;
	//m_total_costo_ocupado=0;
	m_Dibujar=false;
	m_max_total_volumen_ocupado=0;
	//m_max_total_costo_ocupado=0;
	m_objetivo_vol=true;
	m_tipo_mixto=false;
	m_medida1=0;
	m_medida2=0;
	if (caso==1 || caso==2)
	{
		m_full_supported=true;
		//Aqui voy a crear una lista de piezas parecidas
		//para no tener que juntarlas
		//JuntarPiezasParecidas();
		//JuntarPiezasParecidasPesos();
	}
	else
	{
		m_full_supported=false;
	}
	//printf("number of block %d",m_Bloques.size());
}

//esta funcion mira si puedo juntar y los junta si es posible

//esta funcion mira si puedo juntar y los junta si es posible

//esta funcion mira si puedo juntar y los junta si es posible

//Para la creación la x,y,z si es posible rotarla en cada dirección y la cantidad

//Para la creación la x,y,z si es posible rotarla en cada dirección y la cantidad
PIECE::PIECE(int id,int x, bool Px,int y,bool Py, int z, bool Pz, int q,CONTAINER *a,int pes,int s1,int s2, int s3, int cli, int costo)
{

	m_Id=id;
	m_x=x;
	m_Rotate_x=Px;
	m_y=y;
	m_Rotate_y=Py;
	m_z=z;
	m_Rotate_z=Pz;
	m_q=q;
	m_Container=a;
	m_Volumen = m_x*m_y*m_z;
	m_num=0;
			m_peso_pieza = pes;
			m_S_x=(int)s1;
			m_S_y=(int)s2;
			m_S_z=(int)s3;
			m_Costo=costo;
			m_densidad_pieza=(float) m_peso_pieza/m_Volumen;
			m_cliente=cli;
}
//Para la creación la x,y,z si es posible rotarla en cada dirección y la cantidad

BLOQUE::BLOQUE(int id1, int id2,int x, int y, int z, CONTAINER *a,int num1,int num2)
{
	m_Id1=id1;
	m_Id2=id2;
	m_x=x;m_y=y;m_z=z;
	m_Volumen=m_x*m_y*m_z;
//	m_num=__min(;
	m_Container=a;
	m_perdida=false;
	m_Id=m_Container->Get_ListaBloques().size()+1000;
	m_q=__min(m_Container->Get_Piezas()[id1].Get_q(),m_Container->Get_Piezas()[id2].Get_q());
	m_num=m_q;
	//m_peso_bloque=0;//-----------------------------------------
	m_Rotate_z=true;
	m_Rotate_x=false;
	m_Rotate_y=false;
	if (m_Container->Get_Piezas()[id1].Get_Rx()==true && m_Container->Get_Piezas()[id1].Get_Ry()==true &&
		m_Container->Get_Piezas()[id1].Get_Rz()==true && m_Container->Get_Piezas()[id2].Get_Rx()==true && m_Container->Get_Piezas()[id2].Get_Ry()==true &&
		m_Container->Get_Piezas()[id2].Get_Rz()==true)
	{	
		m_Rotate_x=true;
		m_Rotate_y=true;
	}



}
//Para la creación la x,y,z si es posible rotarla en cada dirección y la cantidad

void CONTAINER::EscribirDatosProgramaDibujo()
{
	FILE *fin2;
	char *nombre;
	strcpy(nombre,"");
	strcpy(nombre,m_Nombre);
	strcat(nombre,".dat");
	fin2=fopen(nombre,"a+");
	std::list< CONFIGURACAO >::iterator itl;
	fprintf(fin2,"Contentor:\n Profund. Largura Altura   Limite Peso\n");
	fprintf(fin2,"%d\t%d\t%d\t7000000\n\n",m_X,m_Y,m_Z);
	fprintf(fin2,"Tipo Quant.  Dimensoes   Orient.       Limite Peso       Peso\n");
	fprintf(fin2,"# Destino2\n");
	int i=0;
	for (itl=m_Configuracaos.begin(), i=1;itl!=m_Configuracaos.end();itl++,i++)
	{
		fprintf(fin2,"* %d %d %d %d %d %d %d",i,(*itl).Get_x1(),(*itl).Get_y1(),(*itl).Get_z1(),(*itl).Get_x2(),(*itl).Get_y2(),(*itl).Get_z2());

	}
	fclose(fin2);

}
void CONTAINER::LeerDatosContainer(char *nombre,int opcion)
{
	FILE *fin2;
	m_Pieces.clear();
	m_Q=0;
    int n_cliente;
	char tmp[2];
	strcpy(tmp,"L");
	m_total_volumen=0;
	strcpy(m_Nombre,nombre);
	fin2=fopen(nombre,"r+");
	if (fin2==NULL)
	{
		printf("Problemas al leer el archivo del container, no se encuentra el archivo %s",nombre );
		exit(4);
	}
	switch(opcion)
	{
		case 1:   // CESCHIA
		{
			//Leemos el número de piezas
			fscanf(fin2,"%d\t%d",&m_Q,&n_cliente);
			Setm_num_total_clientes(n_cliente);
			for(int j=0;j<n_cliente;j++)
			{
				m_total_volumen_cliente.push_back(0);
				m_volumen_ocupado_cliente.push_back(0);
				m_superficie_cliente.push_back(1);
			}
			//Las coordenadas del contenedor
			fscanf(fin2,"%d\t%d\t%d",&m_X,&m_Y,&m_Z);
			//Variables temporales para almacenar el número de piezas
			int Id,x,y,z,q,cli,s,s1,s2,s3,Rx,Ry,Rz,costopieza;
			for (int register i=0;i<m_Q;i++)
			{
				m_Numpieces++;
				//Leemos las coordenadas de las piezas
				fscanf(fin2,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n" , &Id, &x, &Rx, &y, &Ry, &z, &Rz,&q,&s,&s1,&s2,&s3,&cli,&costopieza);

				PIECE Piece(Id,x,Rx,y,Ry,z,Rz,q,this,s,s1,s2,s3,cli,costopieza);

				m_total_volumen_cliente[cli]+=Piece.Get_Volumen()*q;
				m_total_volumen+=Piece.Get_Volumen()*q;
				m_Pieces.push_back(Piece);
			}
			//Conforme voy leyendo los datos del container puedo ver cual es la 
			//mas pequena en cada dirección, calculamos minimos para cada dirección

		}
		break;
		case  2:  // PESOS
		{
			//Leemos el número de piezas
			fscanf(fin2,"%d",&m_Q);
			Setm_num_total_clientes(1);
				m_total_volumen_cliente.push_back(0);
				m_volumen_ocupado_cliente.push_back(0);
				m_superficie_cliente.push_back(1);

			//Las coordenadas del contenedor
			fscanf(fin2,"%d\t%d\t%d",&m_X,&m_Y,&m_Z);
			//Variables temporales para almacenar el número de piezas
			int Id,x,y,z,q,cli,s,s1,s2,s3,Rx,Ry,Rz;
			int aux_costopieza=1;
			for (int register i=0;i<m_Q;i++)
			{
				m_Numpieces++;
				//Leemos las coordenadas de las piezas
				fscanf(fin2,"%d %d %d %d %d %d %d %d %d %d %d %d %d\n" , &Id, &x, &Rx, &y, &Ry, &z, &Rz,&q,&s,&s1,&s2,&s3,&cli);
				
				PIECE Piece(Id,x,Rx,y,Ry,z,Rz,q,this,s,s1,s2,s3,cli,aux_costopieza);

				m_total_volumen+=Piece.Get_Volumen()*q;
				m_Pieces.push_back(Piece);
			}
			//Conforme voy leyendo los datos del container puedo ver cual es la 
			//mas pequena en cada dirección, calculamos minimos para cada dirección

		}
		break;
		default:  // DANESES LIU JUNQUEIRA
		{
			//Leemos el número de piezas
			fscanf(fin2,"%d\t%d",&m_Q,&n_cliente);
			Setm_num_total_clientes(n_cliente);
			for(int j=0;j<n_cliente;j++)
			{
				m_total_volumen_cliente.push_back(0);
				m_volumen_ocupado_cliente.push_back(0);
				m_superficie_cliente.push_back(1);
			}
		
			//Las coordenadas del contenedor
			fscanf(fin2,"%d\t%d\t%d",&m_X,&m_Y,&m_Z);
			//Variables temporales para almacenar el número de piezas
			int Id,x,y,z,q,cli,s,s1,s2,s3,Rx,Ry,Rz;
			int aux_s=0;
			int aux_costopieza=1;
			for (int register i=0;i<m_Q;i++)
			{
				m_Numpieces++;
				//Leemos las coordenadas de las piezas
				fscanf(fin2,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n" , &Id, &x, &Rx, &y, &Ry, &z, &Rz,&q,&s,&s1,&s2,&s3,&cli);

				PIECE Piece(Id,x,Rx,y,Ry,z,Rz,q,this,aux_s,999999,999999,999999,cli,aux_costopieza);

				m_total_volumen_cliente[cli]+=Piece.Get_Volumen()*q;
				m_total_volumen+=Piece.Get_Volumen()*q;
				m_Pieces.push_back(Piece);
			}
			//Conforme voy leyendo los datos del container puedo ver cual es la 
			//mas pequena en cada dirección, calculamos minimos para cada dirección
		}
	}
	fclose(fin2);
}
void CONTAINER::MinimaDimensionCliente()
{	
	int i;
	for(i=0;i<m_num_total_clientes;i++)
		vec_minima_longitud.push_back(m_X);
	for (int register icp=0;icp<m_Q;icp++)
	{
		if (m_Pieces[icp].Get_Num()==m_Pieces[icp].Get_q())
			continue;

		if (m_Pieces[icp].Get_Rz()==1)
		{
			if (m_Pieces[icp].Get_x()<vec_minima_longitud[m_Pieces[icp].Get_Cliente()])
				vec_minima_longitud[m_Pieces[icp].Get_Cliente()]=m_Pieces[icp].Get_x();
			if (m_Pieces[icp].Get_y()<vec_minima_longitud[m_Pieces[icp].Get_Cliente()])
				vec_minima_longitud[m_Pieces[icp].Get_Cliente()]=m_Pieces[icp].Get_y();
		}
		if ((m_Pieces[icp].Get_Rx()==1)||(m_Pieces[icp].Get_Ry()==1))
		{
			if (m_Pieces[icp].Get_z()<vec_minima_longitud[m_Pieces[icp].Get_Cliente()])
				vec_minima_longitud[m_Pieces[icp].Get_Cliente()]=m_Pieces[icp].Get_z();
		}
	}
}
//****************
SPACE::SPACE(int x1,int y1, int z1, int x2, int y2,int z2 ,CONTAINER *a)
{
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_x2=x2; m_y2=y2; m_z2=z2;
	m_dx=x2-x1; m_dy=y2-y1; m_dz=z2-z1;
	m_Volumen=m_dx*m_dy*m_dz;
	m_Flag=false;
	m_Container=a;
	if (a->Get_Full_Supported()==false)
		CalcularDistanciaOrigen();
	else
		CalcularDistanciaOrigenFullSupported();

}
SPACE::SPACE(int x1,int y1, int z1, int x2, int y2,int z2 , int soporte,int ry1, int ry2, int rL, CONTAINER *a)
{
	m_x1=x1; m_y1=y1; m_z1=z1;
		m_x2=x2; m_y2=y2; m_z2=z2;
			m_dx=x2-x1; m_dy=y2-y1; m_dz=z2-z1;
				r_y1=m_y1;	r_y2=m_y2; 	r_L=m_dx;
	m_Volumen=m_dx*m_dy*m_dz;
		m_Flag=false;
			m_Container=a;
	m_soporta_peso=soporte; //--------------------------------------------
	if (a->Get_Full_Supported()==false)
			CalcularDistanciaOrigen();
	else
			CalcularDistanciaOrigenFullSupported();
}
SPACE::SPACE(CONTAINER *a,int x1,int y1, int z1, int x2, int y2,int z2)
{
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_x2=m_x1+x2; m_y2=m_y1+y2; m_z2=m_z1+z2;
	m_dx=x2; m_dy=y2; m_dz=z2;
	m_Volumen=m_dx*m_dy*m_dz;
	m_Flag=false;
	m_Container=a;
//	CalcularDistanciaOrigen();
	if (a->Get_Full_Supported()==false)
	{
		if (a->Get_Tipo_Origen()==2)
			CalcularDistanciaOrigenDos();
		if (a->Get_Tipo_Origen()==4)
			CalcularDistanciaOrigenCuatro();
		if (a->Get_Tipo_Origen()==8)
			CalcularDistanciaOrigen();
	}
	else
	CalcularDistanciaOrigenFullSupported();
}
SPACE::SPACE(CONTAINER *a,int x1,int y1, int z1, int x2, int y2,int z2, int ry1, int ry2, int rL, bool flag)
{
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_x2=m_x1+x2; m_y2=m_y1+y2; m_z2=m_z1+z2;
	m_dx=x2; m_dy=y2; m_dz=z2;
	r_y1=ry1; r_y2=ry2; r_L=r_L;
	m_Volumen=m_dx*m_dy*m_dz;
	m_Flag=flag;
	m_Container=a;
	if (a->Get_Full_Supported()==false)
	{
		if (a->Get_Tipo_Origen()==2)
			CalcularDistanciaOrigenDos();
		if (a->Get_Tipo_Origen()==4)
			CalcularDistanciaOrigenCuatro();
		if (a->Get_Tipo_Origen()==8)
			CalcularDistanciaOrigen();
	}
	else
		CalcularDistanciaOrigenFullSupported();
}
void SPACE::CalcularDistanciaOrigenCuatro()
{
	//el primero la distancia al (0,0,0)
	//Tengo que hacer todo lo posible para que esta función evite calculos ya que consume
	//la mayor parte del porcentaje del tiempo
	//Tienen que tener a x1 menor que esto para que pueda ser uno de los 3 siguientes
	if (m_x1<=(m_Container->Get_X()-m_x2))
	{
		if (m_y1<=(m_Container->Get_Y()-m_y2))
		{		
			Cambiar(m_distancia_origen,m_x1,m_y1,m_z1);
			m_origen_distancia=1;
		}
		else
		{
			//Posicion 2
			//solamente cambia la segunda componente por tanto
			Cambiar(m_distancia_origen,m_x1,m_Container->Get_Y()-m_y2,m_z1);
			m_origen_distancia=2;
		}
	}
	else
	{
		//Si el final esta antes del container pues tiene que ser uno de los 
		//primeros
		//Posicion 5
		if (m_y1<=(m_Container->Get_Y()-m_y2))
		{
			Cambiar(m_distancia_origen,m_Container->Get_X()-m_x2,m_y1,m_z1);
			m_origen_distancia=5;
		}
		else
		{
			//Posicion 6
			Cambiar(m_distancia_origen,m_Container->Get_X()-m_x2,m_Container->Get_Y()-m_y2,m_z1);
			m_origen_distancia=6;
		}
	}
}
//Para el contenedor
// 1.(0,0,0) , 2.(0,Y,0)  3.(0,0,Z)  4.(0,Y,Z)  5.(X,0,0)  6.(X,Y,0)  7.(X,0,Z)  8.(X,Y,Z) 
//Para el space
// 1. (m_x1,m_y1, m_z1) ,2 . (m_x1,m_y2,m_z1) 3 (m_x1, m_y1, m_z2) 4 (m_x1,m_y2,m_z2)
// 5. (m_x2,m_y1, m_z1) ,6   (m_x2,m_y2,m_z1) 7 (m_x2,m_y1,m_z2) 8 (m_x2,m_y2,m_z2)
void SPACE::CalcularDistanciaOrigen()
{
	//el primero la distancia al (0,0,0)

	//Tengo que hacer todo lo posible para que esta función evite calculos ya que consume
	//la mayor parte del porcentaje del tiempo
	//Tienen que tener a x1 menor que esto para que pueda ser uno de los 3 siguientes
	if (m_x1<=(m_Container->Get_X()-m_x2))
	{
		if (m_z1<=(m_Container->Get_Z()-m_z2))
		{
			if (m_y1<=(m_Container->Get_Y()-m_y2))
			{	
				Cambiar(m_distancia_origen,m_x1,m_y1,m_z1);
				m_origen_distancia=1;
			}
			else
			{
				//Posicion 2
				//solamente cambia la segunda componente por tanto
				Cambiar(m_distancia_origen,m_x1,m_Container->Get_Y()-m_y2,m_z1);
				m_origen_distancia=2;
			}
		}
		else
		{
			if (m_y1<=(m_Container->Get_Y()-m_y2))
			{
				//Posicion 3
				Cambiar(m_distancia_origen,m_x1,m_y1,m_Container->Get_Z()-m_z2);
				m_origen_distancia=3;	
			}
			else
			{
			//Posicion 4
				Cambiar(m_distancia_origen,m_x1,m_Container->Get_Y()-m_y2,m_Container->Get_Z()-m_z2);
				m_origen_distancia=4;	
			}
		}
	}
	else
	{
		//Si el final esta antes del container pues tiene que ser uno de los 
		//primeros
		//Posicion 5
		if (m_z1<=(m_Container->Get_Z()-m_z2))
		{
			if (m_y1<=(m_Container->Get_Y()-m_y2))
			{
				Cambiar(m_distancia_origen,m_Container->Get_X()-m_x2,m_y1,m_z1);
				m_origen_distancia=5;
			}
			else
			{
				//Posicion 6
				Cambiar(m_distancia_origen,m_Container->Get_X()-m_x2,m_Container->Get_Y()-m_y2,m_z1);
				m_origen_distancia=6;
			}
		}
		else
		{
			if (m_y1<=(m_Container->Get_Y()-m_y2))
			{
				//Posicion 7
				Cambiar(m_distancia_origen,m_Container->Get_X()-m_x2,m_y1,m_Container->Get_Z()-m_z2);
				m_origen_distancia=7;
			}
			else
			{
				//Posicion 8
				Cambiar(m_distancia_origen,m_Container->Get_X()-m_x2,m_Container->Get_Y()-m_y2,m_Container->Get_Z()-m_z2);
				m_origen_distancia=8;
			}
		}
	}
}
//Para el contenedor
// 1.(0,0,0) , 2.(0,Y,0)  3.(0,0,Z)  4.(0,Y,Z)  5.(X,0,0)  6.(X,Y,0)  7.(X,0,Z)  8.(X,Y,Z) 
//Para el space
// 1. (m_x1,m_y1, m_z1) ,2 . (m_x1,m_y2,m_z1) 3 (m_x1, m_y1, m_z2) 4 (m_x1,m_y2,m_z2)
// 5. (m_x2,m_y1, m_z1) ,6   (m_x2,m_y2,m_z1) 7 (m_x2,m_y1,m_z2) 8 (m_x2,m_y2,m_z2)

void SPACE::CalcularDistanciaOrigenFullSupported()
{
/*	if (m_Container->Get_Tipo_Origen()==1)
	{
			Cambiar(m_distancia_origen,m_x1,m_y1,m_z1);
			m_origen_distancia=1;
			return;
	}
*/	//Tengo que hacer todo lo posible para que esta función evite calculos ya que consume
	//la mayor parte del porcentaje del tiempo
	//Tienen que tener a x1 menor que esto para que pueda ser uno de los 3 siguientes
		if (m_y1<=(m_Container->Get_Y()-m_y2))
		{	
			Cambiar(m_distancia_origen,m_x1,m_y1,m_z1);
			m_origen_distancia=1;
		}
		else
		{
			//Posicion 2
			//solamente cambia la segunda componente por tanto
			Cambiar(m_distancia_origen,m_x1,m_Container->Get_Y()-m_y2,m_z1);
			m_origen_distancia=2;
		}
/*	
	if (m_x1<=(m_Container->Get_X()-m_x2))
	{
		if (m_y1<=(m_Container->Get_Y()-m_y2))
		{	
			Cambiar(m_distancia_origen,m_x1,m_y1,m_z1);
			m_origen_distancia=1;
		}
		else
		{
			//Posicion 2
			//solamente cambia la segunda componente por tanto
			Cambiar(m_distancia_origen,m_x1,m_Container->Get_Y()-m_y2,m_z1);
			m_origen_distancia=2;
		}
	}
	else
	{
		//Si el final esta antes del container pues tiene que ser uno de los 
		//primeros
		//Posicion 5
		if (m_y1<=(m_Container->Get_Y()-m_y2))
		{
			Cambiar(m_distancia_origen,m_Container->Get_X()-m_x2,m_y1,m_z1);
			m_origen_distancia=5;
		}
		else
		{
				//Posicion 6
			Cambiar(m_distancia_origen,m_Container->Get_X()-m_x2,m_Container->Get_Y()-m_y2,m_z1);
			m_origen_distancia=6;
		}
	}
	*/
}
void SPACE::CalcularDistanciaOrigenEuclidea()
{
	//el primero la distancia al (0,0,0)
	//Tengo que hacer todo lo posible para que esta función evite calculos ya que consume
	//la mayor parte del porcentaje del tiempo
	//Tienen que tener a x1 menor que esto para que pueda ser uno de los 3 siguientes
	if (m_x1<=(m_Container->Get_X()-m_x2))
	{
		if (m_z1<=(m_Container->Get_Z()-m_z2))
		{
			if (m_y1<=(m_Container->Get_Y()-m_y2))
			{				
				m_val_dist=m_x1^2+m_y1^2+m_z1^2;
				m_origen_distancia=1;
			}
			else
			{
				//Posicion 2
				//solamente cambia la segunda componente por tanto
				m_val_dist=m_x1^2+(m_Container->Get_Y()-m_y2)^2+m_z1^2;
				m_origen_distancia=2;
			}
		}
		else
		{
			if (m_y1<=(m_Container->Get_Y()-m_y2))
			
			{
				//Posicion 3
				m_val_dist=m_x1^2+(m_y2)^2+(m_Container->Get_Z()-m_z2)^2;
				m_origen_distancia=3;	

			}
			else
			{
			//Posicion 4
				m_val_dist=m_x1^2+(m_Container->Get_Y()-m_y2)^2+(m_Container->Get_Z()-m_z2)^2;
				m_origen_distancia=4;	
	
			}
		}
	}
	else
	{
		//Si el final esta antes del container pues tiene que ser uno de los 
		//primeros
		//Posicion 5
		if (m_z1<=(m_Container->Get_Z()-m_z2))
		{
			if (m_y1<=(m_Container->Get_Y()-m_y2))
			{
				m_val_dist=(m_distancia_origen,m_Container->Get_X()-m_x2)^2+(m_y1)^2+(m_z1)^2;

				m_origen_distancia=5;
	
			}
			else
			{
				//Posicion 6
				m_val_dist=(m_distancia_origen,m_Container->Get_X()-m_x2)^2+(m_Container->Get_Y()-m_y2)^2+(m_z1)^2;

				m_origen_distancia=6;
			}
		}
		else
		{
			if (m_y1<=(m_Container->Get_Y()-m_y2))
			{
				//Posicion 7
				m_val_dist=(m_distancia_origen,m_Container->Get_X()-m_x2)^2+(m_y1)^2+(m_Container->Get_Z()-m_z2)^2;
				m_origen_distancia=7;
			}
			else
			{
				//Posicion 8
				m_val_dist=(m_distancia_origen,m_Container->Get_X()-m_x2)^2+(m_Container->Get_Y()-m_y2)^2+(m_Container->Get_Z()-m_z2)^2;

				m_origen_distancia=8;
			}
		}
	}
}
void SPACE::CalcularDistanciaOrigenDos()
{
	//el primero la distancia al (0,0,0)

	//Tengo que hacer todo lo posible para que esta función evite calculos ya que consume
	//la mayor parte del porcentaje del tiempo
	//Tienen que tener a x1 menor que esto para que pueda ser uno de los 3 siguientes
	if (m_y1<=(m_Container->Get_Y()-m_y2))
	{			
		Cambiar(m_distancia_origen,m_x1,m_y1,m_z1);
		m_origen_distancia=1;
	}
	else
	{
		//Posicion 2
		//solamente cambia la segunda componente por tanto
		Cambiar(m_distancia_origen,m_x1,m_Container->Get_Y()-m_y2,m_z1);
		m_origen_distancia=2;
	}
}
//Para el contenedor
// 1.(0,0,0) , 2.(0,Y,0)  3.(0,0,Z)  4.(0,Y,Z)  5.(X,0,0)  6.(X,Y,0)  7.(X,0,Z)  8.(X,Y,Z) 
//Para el space
// 1. (m_x1,m_y1, m_z1) ,2 . (m_x1,m_y2,m_z1) 3 (m_x1, m_y1, m_z2) 4 (m_x1,m_y2,m_z2)
// 5. (m_x2,m_y1, m_z1) ,6   (m_x2,m_y2,m_z1) 7 (m_x2,m_y1,m_z2) 8 (m_x2,m_y2,m_z2)
void SPACE::CambiarEsquina(SPACE &E)
{
	if (E.Get_origen_distancia()==2)
	{
		m_y2=E.Get_y2()-(m_y1-E.Get_y1());
		m_y1=m_y2-m_dy;
	}
	if (E.Get_origen_distancia()==5)
	{
		m_x2=E.Get_x2()-(m_x1-E.Get_x1());
		m_x1=m_x2-m_dx;
	}
	if (E.Get_origen_distancia()==6)
	{
		m_y2=E.Get_y2()-(m_y1-E.Get_y1());
		m_y1=m_y2-m_dy;
		m_x2=E.Get_x2()-(m_x1-E.Get_x1());;
		m_x1=m_x2-m_dx;
	}
}
void CONFIGURACAO::CambiarEsquina(SPACE &E)
{
	int x=m_x2-m_x1;
	int y=m_y2-m_y1;
	if (E.Get_origen_distancia()==2)
	{
		m_y2=E.Get_y2()-(m_y1-E.Get_y1());
		m_y1=m_y2-y;
	}
	if (E.Get_origen_distancia()==5)
	{
		m_x2=E.Get_x2()-(m_x1-E.Get_x1());
		m_x1=m_x2-x;
	}
	if (E.Get_origen_distancia()==6)
	{
		m_y2=E.Get_y2()-(m_y1-E.Get_y1());
		m_y1=m_y2-y;
		m_x2=E.Get_x2()-(m_x1-E.Get_x1());;
		m_x1=m_x2-x;
	}
}
//Original Calcular distancia a origen sin cota
//Para el contenedor
// 1.(0,0,0) , 2.(0,Y,0)  3.(0,0,Z)  4.(0,Y,Z)  5.(X,0,0)  6.(X,Y,0)  7.(X,0,Z)  8.(X,Y,Z) 
//Para el space
// 1. (m_x1,m_y1, m_z1) ,2 . (m_x1,m_y2,m_z1) 3 (m_x1, m_y1, m_z2) 4 (m_x1,m_y2,m_z2)
// 5. (m_x2,m_y1, m_z1) ,6   (m_x2,m_y2,m_z1) 7 (m_x2,m_y1,m_z2) 8 (m_x2,m_y2,m_z2)
void SPACE::CalcularDistanciaOrigenOriginal()
{
}
bool CONTAINER::Mejor_DistA_Que_DistB_Origen(ORIG &A, int VolA,ORIG &B, int VolB)
{
	//Comparo componente a componente
	if (A.GetPrimero()>B.GetPrimero()) return false;
	if (A.GetPrimero()<B.GetPrimero()) return true;
	if (A.GetSegundo()>B.GetSegundo()) return false;
	if (A.GetSegundo()<B.GetSegundo()) return true;
	if (A.GetTercero()>B.GetTercero()) return false;
	if (A.GetTercero()<B.GetTercero()) return true;
	if (VolA<=VolB) return true;
	else 
		return false;
}
//Devuelve true si es mejor la primera que la segunda
bool CONTAINER::Mejor_DistA_Que_DistB_Espacios(ORIG &A, int VolA,ORIG &B, int VolB)
{
	//Comparo componente a componente
	if (A.GetPrimero()>B.GetPrimero()) return false;
	if (A.GetPrimero()<B.GetPrimero()) return true;
	if (A.GetSegundo()>B.GetSegundo()) return false;
	if (A.GetSegundo()<B.GetSegundo()) return true;
	if (A.GetTercero()>B.GetTercero()) return false;
	if (A.GetTercero()<B.GetTercero()) return true;
	if (VolA<=VolB) return true;
	else 
		return false;
}//Devuelve true si es mejor la primera que la segunda
bool CONTAINER::Mejor_DistA_Que_DistB_Espacios_Euclidea(int A, int VolA,int B, int VolB)
{
	if (A<B) return true;
	if (A>B) return false;
	if (VolA<=VolB) return true;
	else 
		return false;
}
//Devuelve true si es mejor el primer espacio al segundo
bool CONTAINER::Mejor_DistA_Que_DistB(SPACE &A ,SPACE &B)
{
//	if (m_full_supported==false)
//	{
	if (A.Get_Distancia().GetPrimero()>B.Get_Distancia().GetPrimero()) return false;
	if (A.Get_Distancia().GetPrimero()<B.Get_Distancia().GetPrimero()) return true;
	if (A.Get_Distancia().GetSegundo()>B.Get_Distancia().GetSegundo()) return false;
	if (A.Get_Distancia().GetSegundo()<B.Get_Distancia().GetSegundo()) return true;
	if (A.Get_Distancia().GetTercero()>B.Get_Distancia().GetTercero()) return false;
	if (A.Get_Distancia().GetTercero()<B.Get_Distancia().GetTercero()) return true;
	if (A.Get_Volumen()<=B.Get_Volumen()) return true;
	else 
		return false;
/*	}
	else
	{
		if (A.Get_z1()<B.Get_z1()) return true;
		if (A.Get_z1()>B.Get_z1()) return false;
		if (A.Get_Volumen()<B.Get_Volumen()) return true;
		return false;
	}
*/
//	return Mejor_DistA_Que_DistB_Espacios(A.Get_Distancia(),A.Get_Volumen(),B.Get_Distancia(),B.Get_Volumen());
//	}
//	else
//		return Mejor_DistA_Que_DistB_Espacios_Euclidea(A.Get_Dist_Euclidea(),A.Get_Volumen(),B.Get_Dist_Euclidea(),B.Get_Volumen());
}
//Esta función es la que me elije un space de la lista de espacios
//el número de espacios tiene que ser de por lo menos uno para que funcione
SPACE & CONTAINER::ElegirSpace()
{
	std::list<SPACE> ::iterator it,elegido;
	bool quedan_todavia=false;
	bool primero=true;;
	//Los recorro todos comparando cual es el mejor
	std::list< SPACE > ::iterator itfin=m_Spaces.end();
//	int k=get_random(1,m_Spaces.size());
	int kk=1;
	for (it=m_Spaces.begin();it!=itfin;kk++)
	{
//		SPACE kk=(*it);
//		if (m_Aleatorizado==true)
//			if (kk==k) return (*it);
		if ((*it).Get_Flag()==false)
		{
			quedan_todavia=true;
			if (primero==true) 
			{
				if (m_Aleatorizado==false)
				{
					if (m_full_supported==true )
						return *it;
				}
				elegido=it;
				primero=false;

			}
			else
			{
				if (m_Aleatorizado==false)
				{
	
					if (m_full_supported==false)
					{
						if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
						{
							elegido=it;
						}
					}
					else
					{
						if ((*it).Get_Volumen()<(*elegido).Get_Volumen())
							elegido=it;
						if ((*it).Get_Volumen()==(*elegido).Get_Volumen())
						{
							if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
							{
								elegido=it;
							}
						}

					}
				}
//				elegido=it;
				else
				{	
					if (m_full_supported==false)
					{
						if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
						{
							elegido=it;
						}
					}
					else
					{
						if ((*it).Get_z1()<(*elegido).Get_z1())
							elegido=it;
						if ((*it).Get_z1()==(*elegido).Get_z1())
						{
							if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
							{
									elegido=it;
							}
						}
					}

				}
			}
			++it;	
		}
		//Funcion que me elimina los espacios 
		//si la quito todo funsiona igual 
		else
		{
			it=m_Spaces.erase(it);
		}
	}
	if (quedan_todavia==false || m_Spaces.size()==0) 
	{
//		printf("No quedan espacios");
//		if (m_max_total_volumen_ocupado==0)
//			m_max_total_volumen_ocupado=m_total_volumen_ocupado;
		if (m_Aleatorizado==false && m_mejora_local==false)
		{
			FILE *fin3;
			fin3=fopen("Results.txt","a+");
			double pt=((double)m_total_volumen_ocupado/(double)m_total_volumen)*100;
			fprintf(fin3,"%s\tV\t%d\tVU\t%d\t%f\n",m_Nombre,m_total_volumen,m_total_volumen_ocupado,pt);
			fclose(fin3);
		}	
		return m_Spaces.front();
	}
	return (*elegido);
}
//Esta función es la que me elije un space de la lista de espacios
//el número de espacios tiene que ser de por lo menos uno para que funcione

void SPACE::ModificarSpace(int x1,int y1, int z1, int x2, int y2, int z2)
{
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_x2=x2; m_y2=y2; m_z2=z2;
	m_dx=x2-x1; m_dy=y2-y1; m_dz=z2-z1;
	m_Volumen=m_dx*m_dy*m_dz;
	if (m_Container->Get_Full_Supported()==false)
	{
		CalcularDistanciaOrigen();
	}
	else
	CalcularDistanciaOrigenFullSupported();
}
void SPACE::ModificarSpacePeso(int x1,int y1, int z1, int x2, int y2, int z2, int soporte, int ry1, int ry2, int rL )
{
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_x2=x2; m_y2=y2; m_z2=z2;
	m_dx=x2-x1; m_dy=y2-y1; m_dz=z2-z1;
	r_y1=ry1; r_y2=ry2; r_L=rL;
	m_Volumen=m_dx*m_dy*m_dz;
	m_soporta_peso=soporte; //--------------------------------------------
	if (m_Container->Get_Full_Supported()==false)
	{
		CalcularDistanciaOrigen();
	}
	else
		CalcularDistanciaOrigenFullSupported();
}
void SPACE::RecortarSpace(int x1,int y1, int z1, int x2, int y2, int z2, int ry1, int ry2, int rL)
{
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_x2=x2; m_y2=y2; m_z2=z2;
	m_dx=x2-x1; m_dy=y2-y1; m_dz=z2-z1;
	r_y1=ry1; r_y2=ry2;     r_L=rL;
	m_Volumen=m_dx*m_dy*m_dz;
	if (m_Container->Get_Full_Supported()==false)
	{
		CalcularDistanciaOrigen();
	}
	else
		CalcularDistanciaOrigenFullSupported();
}

CONFIGURACAO::CONFIGURACAO(CONTAINER *a ,int Id, int x1,int y1, int z1, int x2, int y2, int z2,short int tipo , int num)
{
	m_Id=Id;
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_x2=x2; m_y2=y2; m_z2=z2;
	m_tipo=tipo;
	m_num=num;
	m_Volumen=(x2-x1)*(y2-y1)*(z2-z1);
	m_Container=a;
}
CONFIGURACAO::CONFIGURACAO(CONTAINER *a ,int Id, int x1,int y1, int z1, int tx, int ty, int tz,int dx, int dy, int dz,  short int tipo , int num)
{
	m_Id=Id;
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_x2=x1+tx; m_y2=y1+ty; m_z2=z1+tz;
	m_dx=dx; m_dy=dy; m_dz=dz; 
	m_tipo=tipo;
	m_num=num;
	m_Volumen=(m_x2-m_x1)*(m_y2-m_y1)*(m_z2-m_z1);
	m_Container=a;
}
CONFIGURACAO::CONFIGURACAO(CONTAINER *a ,ORIG sm, int num)
{
	m_Id=99999;
	m_x1=0; m_y1=0; m_z1=0;
	m_x2=0; m_y2=0; m_z2=0;
	m_tipo=0;
	m_set_distancias=sm;
	m_num=num;
	m_Volumen=0;
	//m_Costo=0;
	m_Container=a;
}

int CONTAINER::Estimacion(SPACE &Espacio)
{
	int estima=0;
	for (int icp=0;icp<m_Q;icp++)
	{
		if (m_Pieces[icp].Get_Num()<m_Pieces[icp].Get_q())
		{
//			int esima_pieza=0;
			//Aqui pongo algo por si solamente existe una copia para que no la meta
			//muchas veces
//			if (estima_pieza>0 && (m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num())==1)
//			{
//				estima++;
//				continue;
//			}
			if (m_Pieces[icp].Get_Rz()==true)
			{
				estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
			}
			if (m_Pieces[icp].Get_Ry()==true)
			{
				estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
			}
			if (m_Pieces[icp].Get_Rx()==true)
			{
				estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
			}
//			estima=estima+estima_pieza;
		}
	}
	return estima;
}
int CONTAINER::EstimacionCliente(SPACE &Espacio, int cliente)
{
	int estima=0;
	for (int icp=0;icp<m_Q;icp++)
	{
		if(m_Pieces[icp].Get_Cliente()==cliente)
		{
			if (m_Pieces[icp].Get_Num()<m_Pieces[icp].Get_q())
			{
				if (m_Pieces[icp].Get_Rz()==true)
				{
					estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
					estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				}
				if (m_Pieces[icp].Get_Ry()==true)
				{
					estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
					estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				}
				if (m_Pieces[icp].Get_Rx()==true)
				{
					estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
					estima+=EstimacionConEstaOrientacion(Espacio,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				}
	//			estima=estima+estima_pieza;
			}
		}
	}
	return estima;

}
int CONTAINER::EstimacionPeso(SPACE &Espacio)
{
	int estima=0;
	for (int icp=0;icp<m_Q;icp++)
	{
			if (m_Pieces[icp].Get_Num()<m_Pieces[icp].Get_q())
			{
				if (m_Pieces[icp].Get_Rz()==true)
				{
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_z()*m_Pieces[icp].Get_m_densidad_pieza());
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_z()*m_Pieces[icp].Get_m_densidad_pieza());
				}
				if (m_Pieces[icp].Get_Ry()==true)
				{
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_y()*m_Pieces[icp].Get_m_densidad_pieza());
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_y()*m_Pieces[icp].Get_m_densidad_pieza());
				}
				if (m_Pieces[icp].Get_Rx()==true)
				{
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_x()*m_Pieces[icp].Get_m_densidad_pieza());
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_x()*m_Pieces[icp].Get_m_densidad_pieza());
				}
	//			estima=estima+estima_pieza;
			}
	}
	return estima;
}
int CONTAINER::EstimacionPesoCliente(SPACE &Espacio, int cliente)
{
	int estima=0;
	for (int icp=0;icp<m_Q;icp++)
	{
		if(m_Pieces[icp].Get_Cliente()==cliente)
		{
			if (m_Pieces[icp].Get_Num()<m_Pieces[icp].Get_q())
			{
				if (m_Pieces[icp].Get_Rz()==true)
				{
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_z()*m_Pieces[icp].Get_m_densidad_pieza());
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_z()*m_Pieces[icp].Get_m_densidad_pieza());
				}
				if (m_Pieces[icp].Get_Ry()==true)
				{
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_y()*m_Pieces[icp].Get_m_densidad_pieza());
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_y()*m_Pieces[icp].Get_m_densidad_pieza());
				}
				if (m_Pieces[icp].Get_Rx()==true)
				{
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_x()*m_Pieces[icp].Get_m_densidad_pieza());
					estima+=EstimacionConEstaOrientacionPeso(Espacio,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_x()*m_Pieces[icp].Get_m_densidad_pieza());
				}
	//			estima=estima+estima_pieza;
			}
		}
	}
	return estima;
}
int CONTAINER::EstimacionConEstaOrientacionAlguna(int dx,int dy,int dz, int x, int y,int z, int Id,int piezas_maximas)
{
	if (!(dx>=x &&
		dy>=y &&
		dz>=z))
		return 0;
	else return 1;

}
int CONTAINER::EstimacionConEstaOrientacion(SPACE &Espacio, int x, int y,int z, int Id,int piezas_maximas)
{
	if (!(Espacio.Get_dx()>=x &&
		Espacio.Get_dy()>=y &&
		Espacio.Get_dz()>=z))
		return 0;
//	else 
//		return 1;
	if (piezas_maximas==1) return 1;
	int suma=0;
	int Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
	int Eje_y=__min(Espacio.Get_dy()/y,piezas_maximas);
	int Eje_z=__min(Espacio.Get_dz()/z,piezas_maximas);
	if (Eje_x>1)
		suma++;
	if (Eje_y>1)
		suma++;
	if (Eje_z>1)
		suma++;
	return suma;
}
int CONTAINER::EstimacionConEstaOrientacionPeso(SPACE &Espacio, int x, int y,int z, int Id,int piezas_maximas, int fuerza)
{
	if (!(Espacio.Get_dx()>=x &&
		Espacio.Get_dy()>=y &&
		Espacio.Get_dz()>=z &&
		Espacio.Get_m_soporta_peso()>=fuerza))
		return 0;
//	else 
//		return 1;
	if (piezas_maximas==1) return 1;
	int suma=0;
	int Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
	int Eje_y=__min(Espacio.Get_dy()/y,piezas_maximas);
	int Eje_z=__min(__min(Espacio.Get_dz()/z,piezas_maximas), Espacio.Get_m_soporta_peso()/fuerza);
	if (Eje_x>1)
		suma++;
	if (Eje_y>1)
		suma++;
	if (Eje_z>1)
		suma++;
	return suma;
}
bool CONTAINER::CabeAlguna(int dx,int dy, int dz)
{

	int estima=0;
	for (int icp=0;icp<m_Q;icp++)
	{
		if (m_Pieces[icp].Get_Num()<m_Pieces[icp].Get_q())
		{
//			int esima_pieza=0;
			//Aqui pongo algo por si solamente existe una copia para que no la meta
			//muchas veces
//			if (estima_pieza>0 && (m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num())==1)
//			{
//				estima++;
//				continue;
//			}
			if (m_Pieces[icp].Get_Rz()==true)
			{
				estima+=EstimacionConEstaOrientacionAlguna(dx,dy,dz,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				if (estima>0) return true;

				estima+=EstimacionConEstaOrientacionAlguna(dx,dy,dz,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				if (estima>0) return true;
			}
			if (m_Pieces[icp].Get_Ry()==true)
			{
				estima+=EstimacionConEstaOrientacionAlguna(dx,dy,dz,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				if (estima>0) return true;
				estima+=EstimacionConEstaOrientacionAlguna(dx,dy,dz,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				if (estima>0) return true;
			}
			if (m_Pieces[icp].Get_Rx()==true)
			{
				estima+=EstimacionConEstaOrientacionAlguna(dx,dy,dz,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				if (estima>0) return true;
				estima+=EstimacionConEstaOrientacionAlguna(dx,dy,dz,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num());
				if (estima>0) return true;
			}
//			estima=estima+estima_pieza;
		}
	}
	return false;
}
//Habría que cambiarla para que haga busqueda binaria
//FALTA
void CONTAINER::InsertarOrden( std::list< CONFIGURACAO >  &Lista, CONFIGURACAO  &nuevo)
{
	//Por si solamente hay uno
	if (Lista.size()==0 || nuevo.Get_x1()==0)
	{
		Lista.push_back(nuevo);
		return;
	}

	std::list< CONFIGURACAO >  ::iterator itl;
	for (itl=Lista.begin();itl!=Lista.end();itl++)
	{
		if ((*itl).Get_z2()==nuevo.Get_z1()
			&& ((*itl).Get_x1()<=nuevo.Get_x1()) 
			&& ((*itl).Get_x2()>=nuevo.Get_x2()) 
			&& ((*itl).Get_y1()<=nuevo.Get_y1())
			&& ((*itl).Get_y2()>=nuevo.Get_y2()) )			
		{
			Lista.insert(itl,nuevo);
			return;
		}
	}
	//Si no hay ninguno más pequeño al final
	Lista.push_back(nuevo);
}


//Esta funcion es la que devuelve la mejor configuración
//de las cajas en el espacio
void CONTAINER::PonerConfiguracao(SPACE &Espacio,CONFIGURACAO &Configuracao,std::list<CONFIGURACAO> &lista,bool compactada)	
{
	std::list<CONFIGURACAO> ::iterator it,itfin=lista.end();
	//Tengo que bucar una configuracao que tenga de vertice el mismo que el space
	bool fin=false;
	for (it=lista.begin();it!=itfin && fin!=true;)
	{
		//Me vale cualquiera de los que tengo o mejor
		//lo busco para el que me haya dicho el 
		if (compactada==false)
		{
			switch (Espacio.Get_origen_distancia())
			{
				case 1:
				{
					if (Espacio.Get_x1()==(*it).Get_x1() &&
						Espacio.Get_y1()==(*it).Get_y1() &&
						Espacio.Get_z1()==(*it).Get_z1() )
					{
						Configuracao=(*it);
						m_Configuracaos.push_back((*it));
						it=lista.erase(it);
						fin=true;
					}
					else
						++it;
				}
				break;
				case  2:
				{
					if (Espacio.Get_x1()==(*it).Get_x1() &&
						Espacio.Get_y2()==(*it).Get_y2() &&
						Espacio.Get_z1()==(*it).Get_z1() )
					{
						Configuracao=(*it);
						m_Configuracaos.push_back((*it));
						fin=true;

						it=lista.erase(it);	

					}
					else
						++it;
				}
				break;
				case 3:
				{
					if (Espacio.Get_x1()==(*it).Get_x1() &&
						Espacio.Get_y1()==(*it).Get_y1() &&
						Espacio.Get_z2()==(*it).Get_z2() )
					{
						Configuracao=(*it);
						m_Configuracaos.push_back((*it));
						fin=true;

						it=lista.erase(it);
	
					}
					else
						++it;
				}
				break;
				case  4:
				{
					if (Espacio.Get_x1()==(*it).Get_x1() &&
						Espacio.Get_y2()==(*it).Get_y2() &&
						Espacio.Get_z2()==(*it).Get_z2() )
					{
						Configuracao=(*it);
						m_Configuracaos.push_back((*it));
						fin=true;
						it=lista.erase(it);
	
					}
					else
						++it;
				}
				break;
				case  5:
				{
					if (Espacio.Get_x2()==(*it).Get_x2() &&
						Espacio.Get_y1()==(*it).Get_y1() &&
						Espacio.Get_z1()==(*it).Get_z1() )	

					{
						Configuracao=(*it);
						m_Configuracaos.push_back((*it));
						fin=true;
						it=lista.erase(it);
		
					}
					else
						++it;	
				}
				break;
				case  6:
				{
					if (Espacio.Get_x2()==(*it).Get_x2() &&
						Espacio.Get_y2()==(*it).Get_y2() &&
						Espacio.Get_z1()==(*it).Get_z1() )	

					{
						Configuracao=(*it);
						m_Configuracaos.push_back((*it));
						fin=true;
						it=lista.erase(it);	

					}
					else
						++it;
				}
				break;
				case  7:
				{
					if (Espacio.Get_x2()==(*it).Get_x2() &&
						Espacio.Get_y1()==(*it).Get_y1() &&
						Espacio.Get_z2()==(*it).Get_z2() )	
					{
						Configuracao=(*it);
						m_Configuracaos.push_back((*it));
						fin=true;
						it=lista.erase(it);	
					}
					else
						++it;
				}
				break;
				case  8:
				{
					if (Espacio.Get_x2()==(*it).Get_x2() &&
						Espacio.Get_y2()==(*it).Get_y2() &&
						Espacio.Get_z2()==(*it).Get_z2() )
					{
						Configuracao=(*it);
						m_Configuracaos.push_back((*it));
						fin=true;
						it=lista.erase(it);
					}
					else
						++it;
				}
				break;
			}
		}
		else
		{
			if ((Espacio.Get_x1()==(*it).Get_x1() &&
				Espacio.Get_y1()==(*it).Get_y1() &&
				Espacio.Get_z1()==(*it).Get_z1() ) ||
				(Espacio.Get_x1()==(*it).Get_x1() &&
				Espacio.Get_y2()==(*it).Get_y2() &&
				Espacio.Get_z1()==(*it).Get_z1() ) ||
				(Espacio.Get_x1()==(*it).Get_x1() &&
				Espacio.Get_y1()==(*it).Get_y1() &&
				Espacio.Get_z2()==(*it).Get_z2() ) ||
				(Espacio.Get_x1()==(*it).Get_x1() &&
				Espacio.Get_y2()==(*it).Get_y2() &&
				Espacio.Get_z2()==(*it).Get_z2() ) ||
				(Espacio.Get_x2()==(*it).Get_x2() &&
				Espacio.Get_y1()==(*it).Get_y1() &&
				Espacio.Get_z1()==(*it).Get_z1() ) ||
				(Espacio.Get_x2()==(*it).Get_x2() &&
				Espacio.Get_y2()==(*it).Get_y2() &&
				Espacio.Get_z1()==(*it).Get_z1() ) ||
				(Espacio.Get_x2()==(*it).Get_x2() &&
				Espacio.Get_y1()==(*it).Get_y1() &&
				Espacio.Get_z2()==(*it).Get_z2() ) ||
				(Espacio.Get_x2()==(*it).Get_x2() &&
				Espacio.Get_y2()==(*it).Get_y2() &&
				Espacio.Get_z2()==(*it).Get_z2() ) ||
				(Espacio.Get_x2()>=(*it).Get_x2() &&
				Espacio.Get_y2()>=(*it).Get_y2() &&
				Espacio.Get_z2()>=(*it).Get_z2() &&
				Espacio.Get_x1()<=(*it).Get_x1() &&
				Espacio.Get_y1()<=(*it).Get_y1() &&
				Espacio.Get_z1()<=(*it).Get_z1()))
				{
					Configuracao=(*it);
					m_Configuracaos.push_back((*it));
					it=lista.erase(it);
					fin=true;
				}
				else
					++it;
		}
	}
}
//Calcula cual es la mejor de las posibles configuracao que tiene cada posible 
//rotacion, es decir, hay que pasarle x, y, z y el numero y el devuelve una configuracao
void CONFIGURACAO::MejorColumnaDeUnaPieza(SPACE &Espacio,PIECE &Pieza)
{
	if (Pieza.Get_Rz()==true)
	{
		CompararConColumnas(1,Espacio,Pieza.Get_x(),Pieza.Get_y(),Pieza.Get_z(),Pieza.Get_Id(),Pieza.Get_q()-Pieza.Get_Num());
		CompararConColumnas(2,Espacio,Pieza.Get_y(),Pieza.Get_x(),Pieza.Get_z(),Pieza.Get_Id(),Pieza.Get_q()-Pieza.Get_Num());
	}
	if (Pieza.Get_Ry()==true)
	{
		CompararConColumnas(3,Espacio,Pieza.Get_x(),Pieza.Get_z(),Pieza.Get_y(),Pieza.Get_Id(),Pieza.Get_q()-Pieza.Get_Num());
		CompararConColumnas(4,Espacio,Pieza.Get_z(),Pieza.Get_x(),Pieza.Get_y(),Pieza.Get_Id(),Pieza.Get_q()-Pieza.Get_Num());
	}
	if (Pieza.Get_Rx()==true)
	{
		CompararConColumnas(5,Espacio,Pieza.Get_z(),Pieza.Get_y(),Pieza.Get_x(),Pieza.Get_Id(),Pieza.Get_q()-Pieza.Get_Num());
		CompararConColumnas(6,Espacio,Pieza.Get_y(),Pieza.Get_z(),Pieza.Get_x(),Pieza.Get_Id(),Pieza.Get_q()-Pieza.Get_Num());
	}
}
//Esta funcion puede generar columnas 
void CONFIGURACAO::CompararConColumnas(short int tipo,SPACE &Espacio, int x, int y,int z, int Id,int piezas_maximas)
{
	//La pieza no cabe
	if (!(Espacio.Get_dx()>=x &&
		Espacio.Get_dy()>=y &&
		Espacio.Get_dz()>=z))
		return;
	int Caso=1,numActual=1;
	//Tres posibles casos
	int Eje_x,Eje_y,Eje_z;
	for (Caso=1;Caso<=3;Caso++)
	{
		Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
		Eje_y=__min(Espacio.Get_dy()/y,piezas_maximas);
		Eje_z=__min(Espacio.Get_dz()/z,piezas_maximas);
		//Para que si solo hay uno no haga ninguno mais
		if (Caso>1 && Eje_x==1 && Eje_y==1 && Eje_z==1 )
			break;
		switch (Caso)
		{
			case 1:
				{
					Eje_y=1;
					Eje_z=1;
					numActual=Eje_x;
					break;
				}
			case 2:
				{
					if (Eje_y==1) continue;
					Eje_x=1;
					Eje_z=1;
					//en  y
					numActual=Eje_y;
					break;
				}
			// en z
			case 3:
				{
					if (Eje_z==1) continue;
					Eje_x=1;
					Eje_y=1;
					numActual=Eje_z;
					break;

				}
		}
		//Dimensiones de la pieza las naturales
		//en x, las demas son unas por tanto esta configuracao
		//Tengo que poner eje, que ya esta puesto por el espacio

		ORIG OrigActual(Espacio.Get_dx()-Eje_x*x,Espacio.Get_dy()-Eje_y*y,Espacio.Get_dz()-Eje_z*z);
		int Vol=Eje_x*x*Eje_y*y*Eje_z*z;
		//Para el constructivo 
		if (m_Container->Get_Aleatorizado()==false)
		{
			if (Mejor_DistA_Que_DistB_Configuracaos(m_set_distancias,m_num,OrigActual,numActual,Vol,Eje_x*x,Eje_y*y)==false)
			{
				m_set_distancias=OrigActual;
				CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,Vol);
			}
		}
		//Para hacer un constructivo aleatorizado
		//La diferencia es que aqui tengo que tener una lista que es la que me controla cuantos 
		//pueden caber 
		else
		{
			//Tengo que ver si puedo o no meterla en la lista 
			//En la configuracion que tengo es la pero posible

			//Esta funcion inserta esta en la RCL
			//y a su vez deja esta igual al minimo
			//FALTA
			m_set_distancias=OrigActual;
			CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,Vol);
			InsertarOrdenadaRCL(*this);
			std::list <CONFIGURACAO> ::iterator it;
			m_set_distancias=(*m_Container->Get_ListaRCL().begin()).Get_Distancia();
			m_num=(*m_Container->Get_ListaRCL().begin()).Get_Num();

		}
	}
}
CONFIGURACAO::CONFIGURACAO(CONTAINER *a ,int Id, int x1,int y1, int z1, int tx, int ty, int tz,int dx, int dy, int dz,  short int tipo , int num,short int orig)
{
	m_Id=Id;
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_origen_distancia=orig;
	m_x2=x1+tx; m_y2=y1+ty; m_z2=z1+tz;
	m_dx=dx; m_dy=dy; m_dz=dz; 
	m_tipo=tipo;
	m_num=m_dx*m_dy*m_dz;
	m_Volumen=(m_x2-m_x1)*(m_y2-m_y1)*(m_z2-m_z1);
	m_Container=a;
}
CONFIGURACAO::CONFIGURACAO(CONTAINER *a ,int Id, int x1,int y1, int z1, int x2, int y2, int z2,short int tipo , int num,short int orig)
{
	m_Id=Id;
	m_origen_distancia=orig;
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_x2=x2; m_y2=y2; m_z2=z2;
	m_tipo=tipo;
	m_num=num;
	m_Volumen=(x2-x1)*(y2-y1)*(z2-z1);
	m_Container=a;
}
//void CONFIGURACAO::CompararConCapasPeso(short int tipo,SPACE &Espacio, int x, int y,int z, int Id,int piezas_maximas,int fuerza, int densidad, int soporte, int Volumen,int Costo, int Cliente)
void CONFIGURACAO::CompararConCapasPeso(short int tipo,SPACE &Espacio, int x, int y,int z, int Id,int piezas_maximas,int fuerza, int densidad, int soporte, int Volumen, int Cliente)
{
	if (m_Container->Get_Tipo_Mejora()==3) 
		piezas_maximas=1;
	//La pieza no cabe
	if (!(Espacio.Get_dx()>=x &&
		Espacio.Get_dy()>=y &&
		Espacio.Get_dz()>=z &&
		Espacio.Get_m_soporta_peso()>=fuerza))
		return;
	int Caso=1,numActual=1;
//ç	std::multiset< short int > setActual;
	//Tres posibles casos
	int Eje_x,Eje_y,Eje_z;
	for (Caso=1;Caso<=6;Caso++)
	{
//		if (m_Container->Get_objetivo_vol()==false)	setActual.clear();
		Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
		Eje_y=__min(Espacio.Get_dy()/y,piezas_maximas);
		Eje_z=__min((soporte/fuerza)+1,__min(Espacio.Get_m_soporta_peso()/fuerza,__min(Espacio.Get_dz()/z,piezas_maximas)));
/*		if (m_Container->Get_Aleatorizado()==true)
		{
			Eje_x=get_random(1,Eje_x);
			Eje_y=get_random(1,Eje_y);
			Eje_z=get_random(1,Eje_z);
		}
*/		//Para que si solo hay uno no haga ninguno mais
		if (Caso>1 && Eje_x==1 && Eje_y==1 && Eje_z==1 )
			break;
		switch (Caso)
		{
			case 1:
				{
					Eje_z=1;
					Eje_y=__min(Eje_y, (piezas_maximas/Eje_x));
					numActual=Eje_x*Eje_y;
					break;
				}
			case 2:
				{
					Eje_y=1;
					Eje_z=__min(Eje_z, (piezas_maximas/Eje_x));
					//Si no puedo colocar mas que una ya lo he hecho en el anterior
					if (Eje_z==1) continue;
					numActual=Eje_x*Eje_y;
					break;
				}
			case 3:
				{
					if (Eje_y==1) continue;
					Eje_x=__min(Eje_x, (piezas_maximas/Eje_y));
					if (Eje_x==1) continue;
					Eje_z=1;
					//en  y
					numActual=Eje_y*Eje_x;
					break;
				}
			case 4:
				{
					if (Eje_y==1) continue;
					Eje_x=1;
					Eje_z=__min(Eje_z, (piezas_maximas/Eje_y));
					if (Eje_z==1) continue;
					//en  y
					numActual=Eje_y*Eje_z;
					break;
				}
			// en z
			case 5:
				{
					if (Eje_z==1) continue;
					Eje_y=1;
					Eje_x=__min(Eje_x, (piezas_maximas/Eje_z));
					if (Eje_x==1) continue;

					numActual=Eje_z*Eje_x;
					break;
				}
			case 6:
				{
					if (Eje_z==1) continue;
					Eje_x=1;
					Eje_y=__min(Eje_y, (piezas_maximas/Eje_z));
					if (Eje_x==1) continue;
					numActual=Eje_z*Eje_y;
					break;
				}
		}
/*		if (m_Container->Get_Aleatorizado()==true)
		{
			Eje_x=get_random(1,Eje_x);
			Eje_y=get_random(1,Eje_y);
			Eje_z=get_random(1,Eje_z);

		}
*/
		//Tengo columnas ahora tengo que hacer caras con esa columna
		//En eje y 
		//Dimensiones de la pieza las naturales
		//en x, las demas son unas por tanto esta configuracao
		//Tengo que poner eje, que ya esta puesto por el espacio
		ORIG OrigActual;
		if (m_Container->Get_objetivo_vol()==false)	
		{
			Cambiar(OrigActual,Espacio.Get_dx()-Eje_x*x,Espacio.Get_dy()-Eje_y*y,Espacio.Get_dz()-Eje_z*z);
		}
		int Vol=Eje_x*Eje_y*Eje_z*Volumen;
		//int Cos=Eje_x*Eje_y*Eje_z*Costo;
		//Para el constructivo 
		if (m_Container->Get_Aleatorizado()==false)
		{
			if (m_Container->Get_Tipo_Mejora()!=3)
			{
				if (Mejor_DistA_Que_DistB_Configuracaos(m_set_distancias,m_num,OrigActual,numActual,Vol,Eje_x*x,Eje_y*y)==false)
				{
//				m_set_distancias.clear();
					m_set_distancias=OrigActual;
					//CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,peso,Vol);
					CambiarConfiguracaoPeso(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, fuerza, Espacio,soporte,Vol,Cliente);
				}
			}
			else
			{
				if (Mejor_DistA_Que_DistB_FullSupported(m_set_distancias,m_num,OrigActual,numActual,Vol,Eje_x*x,Eje_y*y,Eje_z*z)==false)
				{
//				m_set_distancias.clear();
					m_set_distancias=OrigActual;
					//CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,peso,Vol);
					CambiarConfiguracaoPeso(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, fuerza, Espacio,soporte,Vol,Cliente);
				}
			}
		}
		//Para hacer un constructivo aleatorizado
		//La diferencia es que aqui tengo que tener una lista que es la que me controla cuantos 
		//pueden caber 
		else
		{
			//Tengo que ver si puedo o no meterla en la lista 
			//En la configuracion que tengo es la pero posible

			//Esta funcion inserta esta en la RCL
			//y a su vez deja esta igual al minimo
			//FALTA
			if (m_Container->Get_objetivo_vol()==false)
			{
//				m_set_distancias.clear();
				m_set_distancias=OrigActual;
			}
			//CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,Vol);
			CambiarConfiguracaoPeso(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, fuerza, Espacio,soporte,Vol,Cliente);
			InsertarOrdenadaRCL(*this);
			if (m_Container->Get_objetivo_vol()==false)
			{
				m_set_distancias=(*m_Container->Get_ListaRCL().begin()).Get_Distancia();
			}
			m_num=(*m_Container->Get_ListaRCL().begin()).Get_Num();
		}
	}
}
/*
void CONTAINER::ReducirBloquesConEstaPieza()
{
	std::list <CONFIGURACAO> ::iterator itC;
	//Primero identificar bloques que no tienen nada arriba 
	for (itC=m_Configuracaos.begin();itC!=m_Configuracaos.end();itC++)
	{
		if (NadieEncimaDeEsteBloque((*itC))==true)
		{
			ReducirBloqueYRellenar((*itC));

		}
	}
}
void CONTAINER::ReducirBloqueYRellenar(CONFIGURACAO &C)
{
	SPACE Espacio
	//Reducir el bloque
	for (int register i=m_dx;i>=1;i--)
	{
		for (int register j=m_dy;j>=1;j--)
		{
			for (int register k=m_dx;k>=1;k--)
			{
				
			}
		}
	}
}
*/
void CONFIGURACAO::CompararConCapas(short int tipo,SPACE &Espacio, int x, int y,int z, int Id,int piezas_maximas,int soporte,int Volumen)
{
//	if (m_Container->Get_Tipo_Mejora()==3) 
//		piezas_maximas=get_random(1,piezas_maximas);
	//La pieza no cabe
	if (!(Espacio.Get_dx()>=x &&
		Espacio.Get_dy()>=y &&
		Espacio.Get_dz()>=z))
		return;
	int Caso=1,numActual=1;
//ç	std::multiset< short int > setActual;
	//Tres posibles casos
	int Eje_x,Eje_y,Eje_z;
	for (Caso=1;Caso<=6;Caso++)
	{
//		if (m_Container->Get_objetivo_vol()==false)	setActual.clear();
		Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
		Eje_y=__min(Espacio.Get_dy()/y,piezas_maximas);
		Eje_z=__min(Espacio.Get_dz()/z,piezas_maximas);
		//Para que si solo hay uno no haga ninguno mais
		if (Caso>1 && Eje_x==1 && Eje_y==1 && Eje_z==1 )
			break;
		switch (Caso)
		{
			case 1:
				{
					Eje_z=1;
					Eje_y=__min(Eje_y, (piezas_maximas/Eje_x));
					numActual=Eje_x*Eje_y;
					break;
				}
			case 2:
				{
					Eje_y=1;
					Eje_z=__min(Eje_z, (piezas_maximas/Eje_x));
					//Si no puedo colocar mas que una ya lo he hecho en el anterior
					if (Eje_z==1) continue;
					numActual=Eje_x*Eje_y;
					break;
				}
			case 3:
				{
					if (Eje_y==1) continue;
					Eje_x=__min(Eje_x, (piezas_maximas/Eje_y));
					if (Eje_x==1) continue;
					Eje_z=1;
					//en  y
					numActual=Eje_y*Eje_x;
					break;
				}
			case 4:
				{
					if (Eje_y==1) continue;
					Eje_x=1;
					Eje_z=__min(Eje_z, (piezas_maximas/Eje_y));
					if (Eje_z==1) continue;
					//en  y
					numActual=Eje_y*Eje_z;
					break;
				}
			// en z
			case 5:
				{
					if (Eje_z==1) continue;
					Eje_y=1;
					Eje_x=__min(Eje_x, (piezas_maximas/Eje_z));
					if (Eje_x==1) continue;

					numActual=Eje_z*Eje_x;
					break;
				}
			case 6:
				{
					if (Eje_z==1) continue;
					Eje_x=1;
					Eje_y=__min(Eje_y, (piezas_maximas/Eje_z));
					if (Eje_x==1) continue;
					numActual=Eje_z*Eje_y;
					break;
				}
		}
/*		if (m_Container->Get_Aleatorizado()==true)
		{
			Eje_x=get_random(1,Eje_x);
			Eje_y=get_random(1,Eje_y);
			Eje_z=get_random(1,Eje_z);

		}
*/
		//Tengo columnas ahora tengo que hacer caras con esa columna
		//En eje y
		 
		//Dimensiones de la pieza las naturales
		//en x, las demas son unas por tanto esta configuracao
		//Tengo que poner eje, que ya esta puesto por el espacio
		ORIG OrigActual;
		if (m_Container->Get_objetivo_vol()==false)	
		{
			Cambiar(OrigActual,Espacio.Get_dx()-Eje_x*x,Espacio.Get_dy()-Eje_y*y,Espacio.Get_dz()-Eje_z*z);
		}
		int Vol=Eje_x*Eje_y*Eje_z*Volumen;
		//Para el constructivo 
		if (m_Container->Get_Aleatorizado()==false)
		{
			if (m_Container->Get_Tipo_Mejora()!=3)
			{
				if (Mejor_DistA_Que_DistB_Configuracaos(m_set_distancias,m_num,OrigActual,numActual,Vol,Eje_x*x,Eje_y*y)==false)
				{
//				m_set_distancias.clear();
					m_set_distancias=OrigActual;
					CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,Vol);
				}
			}
			else
			{
				if (Mejor_DistA_Que_DistB_FullSupported(m_set_distancias,m_num,OrigActual,numActual,Vol,Eje_x*x,Eje_y*y,Eje_z*z)==false)
				{
//				m_set_distancias.clear();
					m_set_distancias=OrigActual;
					CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,Vol);
				}
			}
		}
		//Para hacer un constructivo aleatorizado
		//La diferencia es que aqui tengo que tener una lista que es la que me controla cuantos 
		//pueden caber 
		else
		{
			//Tengo que ver si puedo o no meterla en la lista 
			//En la configuracion que tengo es la pero posible

			//Esta funcion inserta esta en la RCL
			//y a su vez deja esta igual al minimo
			//FALTA
			if (m_Container->Get_objetivo_vol()==false)
			{
//				m_set_distancias.clear();
				m_set_distancias=OrigActual;
			}
			CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,Vol);
			InsertarOrdenadaRCL(*this);
			if (m_Container->Get_objetivo_vol()==false)
			{
				m_set_distancias=(*m_Container->Get_ListaRCL().begin()).Get_Distancia();
			}
			m_num=(*m_Container->Get_ListaRCL().begin()).Get_Num();
		}
	}
}
void CONFIGURACAO::CompararConBloques(short int tipo,SPACE &Espacio, int x, int y,int z, int Id,int piezas_maximas)
{
	//La pieza no cabe
	if (!(Espacio.Get_dx()>=x &&
		Espacio.Get_dy()>=y &&
		Espacio.Get_dz()>=z))
		return;
	int Caso=1,numActual=1;
//ç	std::multiset< short int > setActual;
	//Tres posibles casos
	int Eje_x,Eje_y,Eje_z;
	for (Caso=1;Caso<=6;Caso++)
	{
//		if (m_Container->Get_objetivo_vol()==false)	setActual.clear();
		Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
		Eje_y=__min(Espacio.Get_dy()/y,piezas_maximas);
		Eje_z=__min(Espacio.Get_dz()/z,piezas_maximas);
		//Para que si solo hay uno no haga ninguno mais
		if (Caso>1 && Eje_x==1 && Eje_y==1 && Eje_z==1 )
			break;
		switch (Caso)
		{
			//Eje XYz
			case 1:
				{
					
					Eje_y=__min(Eje_y, (piezas_maximas/Eje_x));
					Eje_z=__min(Eje_z, ((piezas_maximas/Eje_x)/Eje_y));
					numActual=Eje_x*Eje_y*Eje_z;
					break;
				}
				//eje xzy
			case 2:
				{
					Eje_z=__min(Eje_z, (piezas_maximas/Eje_x));
					Eje_y=__min(Eje_y, ((piezas_maximas/Eje_x)/Eje_z));
					numActual=Eje_x*Eje_y*Eje_z;
					//Si no puedo colocar mas que una ya lo he hecho en el anterior
					break;
				}//eje yxz
			case 3:
				{
					if (Eje_y==1) continue;
					Eje_x=__min(Eje_x, (piezas_maximas/Eje_y));
					Eje_z=__min(Eje_z, ((piezas_maximas/Eje_y)/Eje_x));

					if (Eje_x==1) continue;
					//en  y
					numActual=Eje_y*Eje_x*Eje_z;
					break;
				}
			case 4:
				{//eje yzx
					if (Eje_y==1) continue;
					Eje_z=__min(Eje_z, (piezas_maximas/Eje_y));
					Eje_x=__min(Eje_x, ((piezas_maximas/Eje_y)/Eje_z));
					if (Eje_z==1) continue;
					//en  y
					numActual=Eje_y*Eje_z*Eje_x;
					break;
				}

			// en z
			case 5: 
				{//eje zxy
					if (Eje_z==1) continue;
					Eje_x=__min(Eje_x, (piezas_maximas/Eje_z));
					Eje_y=__min(Eje_y, ((piezas_maximas/Eje_z)/Eje_x));

					if (Eje_x==1) continue;

					numActual=Eje_z*Eje_x*Eje_y;
					break;

				}
			case 6:
				{
					if (Eje_z==1) continue;
					Eje_y=__min(Eje_y, (piezas_maximas/Eje_z));
					Eje_x=__min(Eje_x, ((piezas_maximas/Eje_z)/Eje_y));
					if (Eje_x==1) continue;
					numActual=Eje_z*Eje_y*Eje_x;
					break;

				}
		}
		//Tengo columnas ahora tengo que hacer caras con esa columna
		//En eje y
		 
		//Dimensiones de la pieza las naturales
		//en x, las demas son unas por tanto esta configuracao
		//Tengo que poner eje, que ya esta puesto por el espacio
		ORIG OrigActual;
		if (m_Container->Get_objetivo_vol()==false)	
		{
			Cambiar(OrigActual,Espacio.Get_dx()-Eje_x*x,Espacio.Get_dy()-Eje_y*y,Espacio.Get_dz()-Eje_z*z);
		}
		int Vol=Eje_x*x*Eje_y*y*Eje_z*z;
		//Para el constructivo 
		if (m_Container->Get_Aleatorizado()==false)
		{
			if (Mejor_DistA_Que_DistB_Configuracaos(m_set_distancias,m_num,OrigActual,numActual,Vol,Eje_x*x,Eje_y*y)==false)
			{
//				m_set_distancias.clear();
				m_set_distancias=OrigActual;
				CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,Vol);
			}
		}
		//Para hacer un constructivo aleatorizado
		//La diferencia es que aqui tengo que tener una lista que es la que me controla cuantos 
		//pueden caber 
		else
		{
			//Tengo que ver si puedo o no meterla en la lista 
			//En la configuracion que tengo es la pero posible

			//Esta funcion inserta esta en la RCL
			//y a su vez deja esta igual al minimo
			//FALTA
			if (m_Container->Get_objetivo_vol()==false)
			{

//				m_set_distancias.clear();
				m_set_distancias=OrigActual;
			}
			CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,Vol);
			InsertarOrdenadaRCL(*this);
			if (m_Container->Get_objetivo_vol()==false)
			{

				m_set_distancias=(*m_Container->Get_ListaRCL().begin()).Get_Distancia();
			}
			m_num=(*m_Container->Get_ListaRCL().begin()).Get_Num();

		}
	}
}
//Repasar funcion 
//Esta funcion puede generar columnas 
///
//???????????
/*
void CONFIGURACAO::CompararConCapasMejorada(short int tipo,SPACE &Espacio, int x, int y,int z, int Id,int piezas_maximas)
{
	//La pieza no cabe
	if (!(Espacio.Get_dx()>=x &&
		Espacio.Get_dy()>=y &&
		Espacio.Get_dz()>=z))
		return;

	int Caso=1,numActual=1;
	//Tres posibles casos
	int Eje_x_Max,Eje_y_Max,Eje_z_Max,Eje_x,Eje_y,Eje_z;
	for (Caso=1;Caso<=6;Caso++)
	{
//		if (m_Container->Get_objetivo_vol()==false)	setActual.clear();
		Eje_x_Max=__min(Espacio.Get_dx()/x,piezas_maximas);
		Eje_y_Max=__min(Espacio.Get_dy()/y,piezas_maximas);
		Eje_z_Max=__min(Espacio.Get_dz()/z,piezas_maximas);
		//Para que si solo hay uno no haga ninguno mais
		if (Caso>1 && Eje_x_Max==1 && Eje_y_Max==1 && Eje_z_Max==1 )
			break;
		switch (Caso)
		{
			case 1:
				{
					Eje_x=Eje_x_Max;
					Eje_z=1;
					Eje_y=__min(Eje_y_Max, (piezas_maximas/Eje_x_Max));
					numActual=Eje_x*Eje_y;
					break;
				}
			case 2:
				{
					Eje_x=Eje_x_Max;
					Eje_y=1;
					Eje_z=__min(Eje_z_Max, (piezas_maximas/Eje_x_Max));
					//Si no puedo colocar mas que una ya lo he hecho en el anterior
					if (Eje_z==1) continue;
					numActual=Eje_x*Eje_y;
					break;
				}
			case 3:
				{
					Eje_y=Eje_y_Max;
					if (Eje_y==1) continue;
					Eje_x=__min(Eje_x_Max, (piezas_maximas/Eje_y_Max));
					if (Eje_x==1) continue;
					if (Eje_x==Eje_x_Max) 
						continue;
					Eje_z=1;
					//en  y
					numActual=Eje_y*Eje_x;
					break;
				}
			case 4:
				{
					Eje_y=Eje_y_Max;

					if (Eje_y==1) continue;
					Eje_x=1;
					Eje_z=__min(Eje_z_Max, (piezas_maximas/Eje_y_Max));
					if (Eje_z==1) continue;
					//en  y
					numActual=Eje_y*Eje_z;
					break;
				}

			// en z
			case 5:
				{
					Eje_z=Eje_z_Max;

					if (Eje_z==1) continue;
					Eje_y=1;
					Eje_x=__min(Eje_x_Max, (piezas_maximas/Eje_z_Max));
					if (Eje_x==Eje_x_Max) 
						continue;
					if (Eje_x==1) continue;

					numActual=Eje_z*Eje_x;
					break;

				}
			case 6:
				{
					Eje_z=Eje_z_Max;

					if (Eje_z==1) continue;
					Eje_x=1;
					Eje_y=__min(Eje_y_Max, (piezas_maximas/Eje_z_Max));
					if (Eje_y==Eje_y_Max) 
						continue;

					if (Eje_y==1) continue;
					numActual=Eje_z*Eje_y;
					break;

				}
		}
		//Tengo columnas ahora tengo que hacer caras con esa columna
		//En eje y
		 
		//Dimensiones de la pieza las naturales
		//en x, las demas son unas por tanto esta configuracao
		//Tengo que poner eje, que ya esta puesto por el espacio
		ORIG OrigActual;
		if (m_Container->Get_objetivo_vol()==false)	
		{
			Cambiar(OrigActual,Espacio.Get_dx()-Eje_x*x,Espacio.Get_dy()-Eje_y*y,Espacio.Get_dz()-Eje_z*z);
		}
		int Vol=Eje_x*x*Eje_y*y*Eje_z*z;
		//Para el constructivo 
		if (m_Container->Get_Aleatorizado()==false)
		{
			if (Mejor_DistA_Que_DistB_Configuracaos(m_set_distancias,m_num,OrigActual,numActual,Vol)==false)
			{
//				m_set_distancias.clear();
				m_set_distancias=OrigActual;
				CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio);
			}
		}
		//Para hacer un constructivo aleatorizado
		//La diferencia es que aqui tengo que tener una lista que es la que me controla cuantos 
		//pueden caber 
		else
		{
			//Tengo que ver si puedo o no meterla en la lista 
			//En la configuracion que tengo es la pero posible

			//Esta funcion inserta esta en la RCL
			//y a su vez deja esta igual al minimo
			//FALTA
			if (m_Container->Get_objetivo_vol()==false)
			{

//				m_set_distancias.clear();
				m_set_distancias=OrigActual;
			}
			CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio);
			InsertarOrdenadaRCL(*this);
			if (m_Container->Get_objetivo_vol()==false)
			{

				m_set_distancias=(*m_Container->Get_ListaRCL().begin()).Get_Distancia();
			}
			m_num=(*m_Container->Get_ListaRCL().begin()).Get_Num();

		}
	}
}
*/
void CONFIGURACAO::InsertarOrdenadaRCL(CONFIGURACAO &Actual)
{
	//Por si solamente hay uno
	if (m_Container->Get_ListaRCL().size()==0)
	{
		m_Container->Get_ListaRCL().push_back(Actual);
		return;
	}
	//Si tengo mas de los que necesito como voy a meter uno
	//Si no hay ninguno más pequeño al final
	std::list< CONFIGURACAO > ::iterator itl;
	for (itl=m_Container->Get_ListaRCL().begin();itl!=m_Container->Get_ListaRCL().end();itl++)
	{
		if (m_Container->Get_objetivo_vol()==true)
		{
			if ((*itl).Get_Volumen()>Get_Volumen())		
			{
				m_Container->Get_ListaRCL().insert(itl,Actual);
				if (m_Container->Get_ListaRCL().size()>m_Container->Get_TamRCL())
					m_Container->Get_ListaRCL().pop_front();
				return;
			}		
		}
		else
		{
			if (Mejor_DistA_Que_DistB_FullSupported(m_set_distancias,m_num,(*itl).Get_Distancia(),(*itl).Get_Num(),(*itl).Get_Volumen(),(*itl).Get_x2()-(*itl).Get_x1(),(*itl).Get_y2()-(*itl).Get_y1(),(*itl).Get_z2()-(*itl).Get_z1())==false)
			{
				m_Container->Get_ListaRCL().insert(itl,Actual);
				if (m_Container->Get_ListaRCL().size()>m_Container->Get_TamRCL())
					m_Container->Get_ListaRCL().pop_front();
				return;
			}
		}
	}
	//Si es mas grande que todos los demas
	m_Container->Get_ListaRCL().push_back(Actual);
	if (m_Container->Get_ListaRCL().size()>m_Container->Get_TamRCL())
		m_Container->Get_ListaRCL().pop_front();

}
//Esta funcion me cambia la configuracao de la columna o bloque que haya elegido
//Esta funcion esta preparada para si queremos meter mas de una columna en el bloque
//ahora tendríamos tantas columnas como filas en el bloque
void CONFIGURACAO::CambiarConfiguracaoPeso(int numpiezas, int ca,int cb, int cc, int a,int b,int c, int id, short int tipo_rota,int fuerza, SPACE &Espacio,int peso_soporta,int Vol, int Cliente)
//void CONFIGURACAO::CambiarConfiguracaoPeso(int numpiezas, int ca,int cb, int cc, int a,int b,int c, int id, short int tipo_rota,int fuerza, SPACE &Espacio,int peso_soporta,int Vol, int Costo, int Cliente)
{
//	short int tipo=Espacio.Get_origen_distancia();
	m_Id=id;
	m_tipo=tipo_rota;

	//if tipo_rota 1 o 2 es lo que soporte z
	//if tipo_rota 3 o 4 es lo que soporte y
	//if tipo_rota 5 o 6 es lo que soporte x
	m_soporte_peso=Espacio.Get_m_soporta_peso();
	m_soporte_peso_arriba=__min(Espacio.Get_m_soporta_peso()-(fuerza*cc),peso_soporta-(fuerza*(cc-1)));
	m_dx=ca;
	m_dy=cb;
	m_dz=cc;
	m_num=ca*cb*cc;
	m_Volumen=Vol;
	//m_Costo=Costo;
	m_cliente_config=Cliente;
	if (m_Id>=1000)
	{
		m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
		m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
		m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		return;
	}

	switch (Espacio.Get_origen_distancia())
	{
		case 1:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case  2:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case 3:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  4:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  5:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case  6:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case  7:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  8:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
	}
}
//Esta funcion me cambia la configuracao de la columna o bloque que haya elegido
//Esta funcion esta preparada para si queremos meter mas de una columna en el bloque
//ahora tendríamos tantas columnas como filas en el bloque
void CONFIGURACAO::CambiarConfiguracao(int numpiezas, int ca,int cb, int cc, int a,int b,int c, int id, short int tipo_rota, SPACE &Espacio,int Vol)
{
//	short int tipo=Espacio.Get_origen_distancia();
	m_Id=id;
	m_tipo=tipo_rota;
	m_dx=ca;
	m_dy=cb;
	m_dz=cc;
	m_num=ca*cb*cc;
	m_Volumen=Vol;
	if (m_Id>=1000)
	{
		//ahora lo pongo asi luego lo arreglo
		m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
		m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
		m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		return;
	}


	switch (Espacio.Get_origen_distancia())
	{
		case 1:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case  2:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case 3:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  4:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  5:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case  6:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case  7:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  8:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;

	}
}
void CONFIGURACAO::PonerMedidas(int dx,int dy, int dz)
{
	m_dx=dx;
	m_dy=dy;
	m_dz=dz;
	m_num=m_dx*m_dy*m_dz;
	
}
void CONFIGURACAO::PonerMedidas2(int x1,int y1, int z1, int x2, int y2, int z2)
{
	m_x1=x1; m_y1=y1; m_z1=z1;
	m_x2=x2; m_y2=y2; m_z2=z2;
	
}
// Me devuelve true si es mejor la primera que la segunda
bool CONFIGURACAO::Mejor_DistA_Que_DistB_Configuracaos(ORIG &A, int NumA,ORIG &B, int NumB,int Vol,int dx,int dy)
{
	
	//
	
	if (m_Container->Get_objetivo_vol()==true)
	{
		if (m_Volumen<Vol) return false;
		if (m_Volumen==Vol && (((m_x2-m_x1)*(m_y2-m_y1))<(dx*dy))) return false;
		if (m_Volumen==Vol && m_Id>=1000) return false;
		if (m_Volumen==Vol && (NumA>NumB )) return false;
		if (m_Volumen==Vol && NumA>NumB) return false;
		if (m_Volumen==Vol) return get_random(0,1);
		return true;
	}

	//Comparo componente a componente
	//Comparo componente a componente
	if (A.GetPrimero()>B.GetPrimero()) return false;
	if (A.GetPrimero()<B.GetPrimero()) return true;
	if (A.GetSegundo()>B.GetSegundo()) return false;
	if (A.GetSegundo()<B.GetSegundo()) return true;
	if (A.GetTercero()>B.GetTercero()) return false;
	if (A.GetTercero()<B.GetTercero()) return true;
	if (NumA<=NumB) return true;
	else 
		return false;
}
// Me devuelve true si es mejor la primera que la segunda
bool CONFIGURACAO::Mejor_DistA_Que_DistB_Configuracaos(CONFIGURACAO &C)
{
	
	//
	if (m_Container->Get_objetivo_vol()==true)
	{//Solamente funcion objetivo
		if (m_Volumen<C.Get_Volumen()) return false;
		if (m_Volumen==C.Get_Volumen() && m_num>C.Get_Num()) return false;
		if (m_Volumen==C.Get_Volumen() && m_num>C.Get_Num()) return false;
		if (m_Volumen==C.Get_Volumen()) return get_random(0,1);
		return true;
	}

	//Comparo componente a componente
	//Comparo componente a componente
	if (m_set_distancias.GetPrimero()>C.Get_Distancia().GetPrimero()) return false;
	if (m_set_distancias.GetPrimero()<C.Get_Distancia().GetPrimero()) return true;
	if (m_set_distancias.GetSegundo()>C.Get_Distancia().GetSegundo()) return false;
	if (m_set_distancias.GetSegundo()<C.Get_Distancia().GetSegundo()) return true;
	if (m_set_distancias.GetTercero()>C.Get_Distancia().GetTercero()) return false;
	if (m_set_distancias.GetTercero()<C.Get_Distancia().GetTercero()) return true;
	if (m_num<=C.Get_Num()) return true;
	else 
		return false;
}
/*
int CONFIGURACAO::CuantasEncima(int x, int y)
{
	int suma=0;
	for (int i=0;i<m_Q;i++)
	{
		if (m_Pieces[i].Get_Num()<m_Pieces[i].Get_q())
		{
			if (
		}
	}
}*/
// Me devuelve true si es mejor la primera que la segunda
bool CONFIGURACAO::Mejor_DistA_Que_DistB_FullSupported(ORIG &A, int NumA,ORIG &B, int NumB,int Vol,int dx,int dy, int dz)
{
	//otra opcion mucho mas compleja es calcular cuantas podrian estar encima de esta y colocar esa
	//pieza
//	if (CuantasEncima(m_x2-m_x1,m_y2-m_y1)<CuantasEncima(dx,dy)) return false;
//	else return true;



		//area
		if (((m_x2-m_x1)*(m_y2-m_y1))<(dx*dy)) return false;
//		if (m_Volumen==Vol && NumA>NumB) return false;
		//si tienen igual area por volumen
		if (m_Volumen>Vol && ((m_x2-m_x1)*(m_y2-m_y1))==(dx*dy)) return false;
/*		if (((m_x2-m_x1)*(m_y2-m_y1))>(dx*dy)) return true;
		//Si tienen igual volumen e igual area 
		if (A.GetPrimero()>B.GetPrimero()) return false;
		if (A.GetPrimero()<B.GetPrimero()) return true;
		if (A.GetSegundo()>B.GetSegundo()) return false;
		if (A.GetSegundo()<B.GetSegundo()) return true;
		if (A.GetTercero()>B.GetTercero()) return false;
		if (A.GetTercero()<B.GetTercero()) return true;
		if (NumA<=NumB) return true;
		else 
			return false;*/
		//Solamente funcion objetivo
		//si ya no caben mas encima
		//area
/*		if (((m_x2-m_x1)*(m_y2-m_y1))<(dx*dy)) return false;
		else
		{
			if (((m_x2-m_x1)*(m_y2-m_y1))==(dx*dy))
			{
				if (m_Volumen>Vol)
				{
					return true;
				}
				if (m_Volumen==Vol)
				{
					//Para que ponga las mas cuadradas
					if ((m_x2-m_x1)+(m_y2-m_y1)<dx+dy)
						return true;
					else
						return false;
				}
			}
		}*/

/*		if (((m_x2-m_x1)*(m_y2-m_y1))>(dx*dy)) return true;
		//Si tienen igual volumen e igual area 
		if (A.GetPrimero()>B.GetPrimero()) return false;
		if (A.GetPrimero()<B.GetPrimero()) return true;
		if (A.GetSegundo()>B.GetSegundo()) return false;
		if (A.GetSegundo()<B.GetSegundo()) return true;
		if (A.GetTercero()>B.GetTercero()) return false;
		if (A.GetTercero()<B.GetTercero()) return true;
		if (NumA<=NumB) return true;
		else 
			return false;*/
		return true;

	//Comparo componente a componente
	//Comparo componente a componente
	if (A.GetPrimero()>B.GetPrimero()) return false;
	if (A.GetPrimero()<B.GetPrimero()) return true;
	if (A.GetSegundo()>B.GetSegundo()) return false;
	if (A.GetSegundo()<B.GetSegundo()) return true;
	if (A.GetTercero()>B.GetTercero()) return false;
	if (A.GetTercero()<B.GetTercero()) return true;
	if (NumA<=NumB) return true;
	else 
		return false;
}
// Me devuelve true si es mejor la primera que la segunda
bool CONFIGURACAO::Mejor_DistA_Que_DistB_Pesos(ORIG &A, int NumA,ORIG &B, int NumB,int Vol,int dx,int dy, int dz)
{

	//esta funcion solo tiene sentido si todas las cajas tienen la misma densidad
	//podemos tener una que sea algo asi
//	if ((__min(m_Z-(Espacio.Get_z()+dz+peso_z),0)*m_dx*m_dy)
	return true;
	//otra opcion mucho mas compleja es calcular cuantas podrian estar encima de esta y colocar esa
	//pieza
//	if (CuantasEncima(m_x2-m_x1,m_y2-m_y1)<CuantasEncima(dx,dy)) return false;
//	else return true;
}

void CONTAINER::ReducirBloquesConEstaPieza(int kblo,int cuantos)
{
	std::list< BLOQUE> ::iterator itb;
	std::list<BLOQUE> ::iterator itbfin=m_Bloques.end();
	for (itb=m_Bloques.begin();itb!=itbfin;)
	{
		
		if (kblo==(*itb).Get_Id1() || kblo==(*itb).Get_Id2())
		{
			if (m_Pieces[kblo].Get_Num()==m_Pieces[kblo].Get_q())
				itb=m_Bloques.erase(itb);
			else
			{
				if (kblo==(*itb).Get_Id1())
				(*itb).Set_Num((*itb).Get_Num()-ceil((double)cuantos/(double)(*itb).Get_Num1()));
				if (kblo==(*itb).Get_Id2())
				(*itb).Set_Num((*itb).Get_Num()-ceil((double)cuantos/(double)(*itb).Get_Num2()));
				if ((*itb).Get_Num()<=0) 
					itb=m_Bloques.erase(itb);
				else	
					++itb;
			}
		}
		else
			++itb;
	}
}
void CONTAINER::EliminarBloquesConEstaPieza(int kblo)
{
	std::list< BLOQUE> ::iterator itb;
	std::list<BLOQUE> ::iterator itbfin=m_Bloques.end();
	for (itb=m_Bloques.begin();itb!=itbfin;)
	{
		if (kblo==(*itb).Get_Id1() || kblo==(*itb).Get_Id2())
			itb=m_Bloques.erase(itb);
		else
			++itb;
	}
}
BLOQUE  &CONTAINER::BuscarPiezasBloque(int kblo)
{
	std::list< BLOQUE> ::iterator itb;
	for (itb=m_Bloques.begin();itb!=m_Bloques.end();itb++)
	{
		if (kblo==(*itb).Get_Id())
			return (*itb);
	}
	return (*m_Bloques.begin());
}

void CONTAINER::CambiarConfiguracaoBloque(CONFIGURACAO &C, SPACE &E, BLOQUE &B, CONFIGURACAO &C1, CONFIGURACAO &C2,std::list < SPACE > &lista)
{
	C1.Set_Id(B.Get_Id1());
	C2.Set_Id(B.Get_Id2());
	C1.Set_dx(C.Get_dx());
	C1.Set_dy(C.Get_dy());
	C1.Set_dz(C.Get_dz());
	C2.Set_dx(C.Get_dx());
	C2.Set_dy(C.Get_dy());
	C2.Set_dz(C.Get_dz());
	C1.Set_Num(C.Get_Num()*B.Get_Num1());
	C2.Set_Num(C.Get_Num()*B.Get_Num2());
	switch (C.Get_Tipo())
	{
		//original
		case 1:
		{
			C1.PonerMedidas2(C.Get_x1(),C.Get_y1(),C.Get_z1(),C.Get_x1()+(B.Get_x_P1()*C.Get_dx()),C.Get_y1()+(B.Get_y_P1()*C.Get_dy()),C.Get_z1()+(B.Get_z()*C.Get_dz()));
			C2.PonerMedidas2(C1.Get_x2(),C1.Get_y1(),C1.Get_z1(),C1.Get_x2()+(B.Get_x_P2()*C.Get_dx()),C1.Get_y1()+(B.Get_y_P2()*C.Get_dy()*B.Get_Num2()),C.Get_z1()+(B.Get_z()*C.Get_dz()));
			//Ahora pongo los espacios vacios 
			//son tres uno en el que no podre poner nada
			//y dos grandes
			SPACE Espacio(this,C.Get_x1(),C.Get_y1(),C.Get_z2(),C.Get_x2()-C.Get_x1(),C2.Get_y2()-C.Get_y1(),E.Get_z2()-C.Get_z2());
			if (B.Get_Perdida()==true)
			{
//				Asi tendrimaos dos arriba este mas pequeno

//				SPACE Espacio2(this,C.Get_x1(),C.Get_y1(),C.Get_z2(),C1.Get_x2()-C.Get_x1(),C1.Get_y2()-C.Get_y1(),E.Get_z2()-C.Get_z2() );
				SPACE Espacio3(this,C1.Get_x2(),C2.Get_y2(),C.Get_z1(),E.Get_x2()-C1.Get_x2(),E.Get_y2()-C2.Get_y2(),E.Get_z2()-C.Get_z1());
				if (E.Get_origen_distancia()!=1)
				{
//					Espacio2.CambiarEsquina(E);
					Espacio3.CambiarEsquina(E);

				}
//				lista.push_back(Espacio2);
				lista.push_back(Espacio3);
			}
			if (E.Get_origen_distancia()!=1)
			{
				C1.CambiarEsquina(E);
				C2.CambiarEsquina(E);
				Espacio.CambiarEsquina(E);
				C.CambiarEsquina(E);

			}
			lista.push_back(Espacio);

			//el pequeno es el que tengo que meter 


		}
		break;
		case  2:
		{
			C1.PonerMedidas2(C.Get_x1(),C.Get_y1(),C.Get_z1(),C.Get_x1()+(B.Get_y_P1()*C.Get_dx()),C.Get_y1()+(B.Get_x_P1()*C.Get_dy()),C.Get_z1()+(B.Get_z()*C.Get_dz()));
			C2.PonerMedidas2(C1.Get_x1(),C1.Get_y2(),C1.Get_z1(),C1.Get_x1()+(B.Get_y_P2()*C.Get_dx()*B.Get_Num2()),C1.Get_y2()+(B.Get_x_P2()*C.Get_dy()),C.Get_z1()+(B.Get_z()*C.Get_dz()));
			//Ahora pongo los espacios vacios 
			//son tres uno en el que no podre poner nada
			//y dos grandes
			SPACE Espacio(this,C.Get_x1(),C.Get_y1(),C.Get_z2(),C2.Get_x2()-C.Get_x1(),C.Get_y2()-C.Get_y1(),E.Get_z2()-C.Get_z2());
			if (B.Get_Perdida()==true)
			{
//				Asi tendrimaos dos arriba este mas pequeno
//				SPACE Espacio2(this,C.Get_x1(),C.Get_y1(),C.Get_z2(),C1.Get_x2()-C.Get_x1(),C1.Get_y2()-C.Get_y1(),E.Get_z2()-C.Get_z2() );
				SPACE Espacio3(this,C2.Get_x2(),C1.Get_y2(),C.Get_z1(),E.Get_x2()-C2.Get_x2(),E.Get_y2()-C1.Get_y2(),E.Get_z2()-C.Get_z1());

				if (E.Get_origen_distancia()!=1)
				{
//					Espacio2.CambiarEsquina(E);
					Espacio3.CambiarEsquina(E);

				}
//				lista.push_back(Espacio2);
				lista.push_back(Espacio3);
			}
			if (E.Get_origen_distancia()!=1)
			{
				C1.CambiarEsquina(E);
				C2.CambiarEsquina(E);
				Espacio.CambiarEsquina(E);
				C.CambiarEsquina(E);

			}
			lista.push_back(Espacio);

				//el pequeno va a caber nada
		}
/*		break;
		case 3:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  4:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  5:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case  6:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case  7:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
*/	}


}
void CONTAINER::ColocarOrdenadosNuevos(std::list< SPACE > &lista_temp)
{
	std::list< SPACE >::iterator it;
	for (it=lista_temp.begin();it!=lista_temp.end();it++)
	{
//		SPACE kk=(*it);
		InsertarOrden((*it));
	}

}
void CONTAINER::ActualizarConfiguracaoGravedad(CONFIGURACAO &E, int x1,int y1, int z1, int x2, int y2, int z2,std::list <CONFIGURACAO> &lista_temp, short int sentido)
{
	//Podemos tener seis posibles Configuracaos nuevos
	int dimx=E.Get_x2()-E.Get_x1();
	int dimy=E.Get_y2()-E.Get_y1();
	int dimz=E.Get_z2()-E.Get_z1();
	//Para un de los otros dos lo hago como la caja y el otro como es
		//Recordar tengo que poner cuantos hay en cada direccion Saludines
	if (sentido==0)
	{
		//Izquierda: if (xE1-xC1)>0 espaço es ((xE1-xC1),yE2-yE1,zE2-zE1)  v: (xE1,yE1,zE1)
		if ((x1-E.Get_x1())>0)
		{
			//Si se da esto es un Configuracao en el que no voy a poder colocar nada 
			//Por ahora no lo creo
			if (0<__min(__min((x1-E.Get_x1()),dimy),dimz) )
			{
				CONFIGURACAO Configuracao(this, E.Get_Id(),E.Get_x1(),E.Get_y1(),E.Get_z1(),E.Get_x1()+(x1-E.Get_x1()),E.Get_y1()+dimy,E.Get_z1()+dimz ,E.Get_Tipo(),0);
				//Tengo que decirle cuantas en el eje x, eje y y ejez
				Configuracao.PonerMedidas((x1-E.Get_x1())/((E.Get_x2()-E.Get_x1())/E.Get_dx()),E.Get_dy(),E.Get_dz());
				lista_temp.push_back(Configuracao);
			}
		}


		//Derecha:  if (xC2-xE2)>0 espaço es ((xC2-xE2),yE2-yE1,zE2-zE1) v: (xC2,yE1,zE1)
		if ((E.Get_x2()-x2)>0)
		{
			if (0<__min(__min((E.Get_x2()-x2),dimy),dimz) )
			{

				CONFIGURACAO Configuracao(this, E.Get_Id(),x2,E.Get_y1(),E.Get_z1(),x2+(E.Get_x2()-x2),E.Get_y1()+dimy,E.Get_z1()+dimz,E.Get_Tipo(),0);
				Configuracao.PonerMedidas((E.Get_x2()-x2)/((E.Get_x2()-E.Get_x1())/E.Get_dx()),E.Get_dy(),E.Get_dz());

				lista_temp.push_back(Configuracao);
			}
		}
		//Estos dos mas pequños
		//Abajo
		//Abajo: if (yC1-yE1)>0 espaço es (xE2-xE1, (yC1-yE1),zE2-zE1) v: (xE1,yC1,zE1)
		if ((y1-E.Get_y1())>0)
		{
			if (0<__min(__min(dimx,(y1-E.Get_y1())),dimz) )
			{

				CONFIGURACAO Configuracao(this, E.Get_Id(),x1,E.Get_y1(),E.Get_z1(),x1+x2-x1,E.Get_y1()+(y1-E.Get_y1()),E.Get_z1()+dimz  ,E.Get_Tipo(),0);
				Configuracao.PonerMedidas(1,(y1-E.Get_y1())/((E.Get_y2()-E.Get_y1())/E.Get_dy()),E.Get_dz());

				lista_temp.push_back(Configuracao);
			}
		}
		//Arriba
		//Arriba:  if (yE2-yC2)>0 espaço es (xE2-xE1, (yE2-yC2),zE2-zE1) v: (xE1,yE1,zE1)
		if ((E.Get_y2()-y2)>0)
		{
		if (0<__min(__min(dimx,(E.Get_y2()-y2)),dimz) )
		{

			CONFIGURACAO Configuracao(this, E.Get_Id(),x1,y2,E.Get_z1(),x1+x2-x1,y2+(E.Get_y2()-y2),E.Get_z1()+dimz  ,E.Get_Tipo(),0);
			Configuracao.PonerMedidas(1,(E.Get_y2()-y2)/((E.Get_y2()-E.Get_y1())/E.Get_dy()),E.Get_dz());

			lista_temp.push_back(Configuracao);
		}
	}
	}
	if (sentido==1)
	{

	//ya que los de arriba y abajo no son necesairos
	//Fuera
	//Furera: if (zE1-zC1)>0 espaço es (xE2-xE1,yE2-yE1, (zE1-zC1)) v: (xE1,yE1,zC1)
	if ((z1-E.Get_z1())>0)
	{
		if (0<__min(__min(dimx,dimy),(z1-E.Get_z1())) )
		{

			CONFIGURACAO Configuracao(this, E.Get_Id(),E.Get_x1(),E.Get_y1(),E.Get_z1(),E.Get_x1()+dimx,E.Get_y1()+dimy,E.Get_z1()+(z1-E.Get_z1()),E.Get_Tipo(),0);
			Configuracao.PonerMedidas(E.Get_dx(),E.Get_dy(),(z1-E.Get_z1())/((E.Get_z2()-E.Get_z1())/E.Get_dz()));
			lista_temp.push_back(Configuracao);
		}
	}
	//Dentro
	//Dentro:  if (zC2-zE2)>0 espaço es (xE2-xE1,yE2-yE1, (zC2-zE2)) v: (xE1,yE1,zE1)
	if ((E.Get_z2()-z2)>0)
	{
		if (0<__min(__min(dimx,dimy),(E.Get_z2()-z2)) )
		{

			CONFIGURACAO Configuracao(this, E.Get_Id(),E.Get_x1(),E.Get_y1(),z2,E.Get_x1()+dimx,E.Get_y1()+dimy,z2+(E.Get_z2()-z2) ,E.Get_Tipo(),0);
			Configuracao.PonerMedidas(E.Get_dx(),E.Get_dy(),(E.Get_z2()-z2)/((E.Get_z2()-E.Get_z1())/E.Get_dz()));

			lista_temp.push_back(Configuracao);
		}
	}

		//Estos dos mas pequños
	//Abajo
	//Abajo: if (yC1-yE1)>0 espaço es (xE2-xE1, (yC1-yE1),zE2-zE1) v: (xE1,yC1,zE1)
	if ((y1-E.Get_y1())>0)
	{
		if (0<__min(__min(dimx,(y1-E.Get_y1())),dimz) )
		{

			CONFIGURACAO Configuracao(this, E.Get_Id(),E.Get_x1(),E.Get_y1(),z1,E.Get_x1()+dimx,E.Get_y1()+(y1-E.Get_y1()),z1+z2-z1  ,E.Get_Tipo(),0);
			Configuracao.PonerMedidas(E.Get_dx(),(y1-E.Get_y1())/((E.Get_y2()-E.Get_y1())/E.Get_dy()),1);
			lista_temp.push_back(Configuracao);
		}
	}
	//Arriba
	//Arriba:  if (yE2-yC2)>0 espaço es (xE2-xE1, (yE2-yC2),zE2-zE1) v: (xE1,yE1,zE1)
	if ((E.Get_y2()-y2)>0)
	{
		if (0<__min(__min(dimx,(E.Get_y2()-y2)),dimz) )
		{

			CONFIGURACAO Configuracao(this, E.Get_Id(),E.Get_x1(),y2,z1,E.Get_x1()+dimx,y2+(E.Get_y2()-y2),z1+z2-z1  ,E.Get_Tipo(),0);
			Configuracao.PonerMedidas(E.Get_dx(),(E.Get_y2()-y2)/((E.Get_y2()-E.Get_y1())/E.Get_dy()),1);

			lista_temp.push_back(Configuracao);
		}
	}
	}

	if (sentido==2)
	{

	//ya que los de arriba y abajo no son necesairos
	//Fuera
	//Furera: if (zE1-zC1)>0 espaço es (xE2-xE1,yE2-yE1, (zE1-zC1)) v: (xE1,yE1,zC1)
	if ((z1-E.Get_z1())>0)
	{
		if (0<__min(__min(dimx,dimy),(z1-E.Get_z1())) )
		{

			CONFIGURACAO Configuracao(this, E.Get_Id(),x1,E.Get_y1(),E.Get_z1(),x2,E.Get_y1()+dimy,E.Get_z1()+(z1-E.Get_z1()),E.Get_Tipo(),0);
			Configuracao.PonerMedidas(1,E.Get_dy(),(z1-E.Get_z1())/((E.Get_z2()-E.Get_z1())/E.Get_dz()));
			lista_temp.push_back(Configuracao);
		}
	}
	//Dentro
	//Dentro:  if (zC2-zE2)>0 espaço es (xE2-xE1,yE2-yE1, (zC2-zE2)) v: (xE1,yE1,zE1)
	if ((E.Get_z2()-z2)>0)
	{
		if (0<__min(__min(dimx,dimy),(E.Get_z2()-z2)) )
		{

			CONFIGURACAO Configuracao(this, E.Get_Id(),x1,E.Get_y1(),z2,x2,E.Get_y1()+dimy,z2+(E.Get_z2()-z2) ,E.Get_Tipo(),0);
			Configuracao.PonerMedidas(1,E.Get_dy(),(E.Get_z2()-z2)/((E.Get_z2()-E.Get_z1())/E.Get_dz()));

			lista_temp.push_back(Configuracao);
		}
	}

		//Estos dos mas pequños
	//Abajo
	//Abajo: if (yC1-yE1)>0 espaço es (xE2-xE1, (yC1-yE1),zE2-zE1) v: (xE1,yC1,zE1)
		//Izquierda: if (xE1-xC1)>0 espaço es ((xE1-xC1),yE2-yE1,zE2-zE1)  v: (xE1,yE1,zE1)
		if ((x1-E.Get_x1())>0)
		{
			//Si se da esto es un Configuracao en el que no voy a poder colocar nada 
			//Por ahora no lo creo
			if (0<__min(__min((x1-E.Get_x1()),dimy),dimz) )
			{
				CONFIGURACAO Configuracao(this, E.Get_Id(),E.Get_x1(),E.Get_y1(),E.Get_z1(),E.Get_x1()+(x1-E.Get_x1()),E.Get_y1()+dimy,E.Get_z1()+dimz ,E.Get_Tipo(),0);
				//Tengo que decirle cuantas en el eje x, eje y y ejez
				Configuracao.PonerMedidas((x1-E.Get_x1())/((E.Get_x2()-E.Get_x1())/E.Get_dx()),E.Get_dy(),E.Get_dz());
				lista_temp.push_back(Configuracao);
			}
		}


		//Derecha:  if (xC2-xE2)>0 espaço es ((xC2-xE2),yE2-yE1,zE2-zE1) v: (xC2,yE1,zE1)
		if ((E.Get_x2()-x2)>0)
		{
			if (0<__min(__min((E.Get_x2()-x2),dimy),dimz) )
			{

				CONFIGURACAO Configuracao(this, E.Get_Id(),x2,E.Get_y1(),E.Get_z1(),x2+(E.Get_x2()-x2),E.Get_y1()+dimy,E.Get_z1()+dimz,E.Get_Tipo(),0);
				Configuracao.PonerMedidas((E.Get_x2()-x2)/((E.Get_x2()-E.Get_x1())/E.Get_dx()),E.Get_dy(),E.Get_dz());

				lista_temp.push_back(Configuracao);
			}
		}

	}

}
//Habría que cambiarla para que haga busqueda binaria
//FALTA
void CONTAINER::InsertarOrden(SPACE &Espacio)
{
	//Por si solamente hay uno
	if (m_Spaces.size()==0)
	{
		m_Spaces.push_back(Espacio);
		return;
	}

	std::list<SPACE> ::iterator itl;
	for (itl=m_Spaces.begin();itl!=m_Spaces.end();itl++)
	{
		if ((*itl).Get_Volumen()>Espacio.Get_Volumen())
		{
			m_Spaces.insert(itl,Espacio);
			return;
		}
	}
	//Si no hay ninguno más pequeño al final
	m_Spaces.push_back(Espacio);
}
//Habría que cambiarla para que haga busqueda binaria
//FALTA
void CONTAINER::InsertarOrden(std::list< SPACE > & lista, SPACE &Espacio)
{
	//Por si solamente hay uno
	if (lista.size()==0)
	{

		lista.push_back(Espacio);
		return;
	}

	std::list<SPACE> ::iterator itlL;
	for (itlL=lista.begin();itlL!=lista.end();itlL++)
	{
		if ((*itlL).Get_Volumen()>Espacio.Get_Volumen())
		{
			lista.insert(itlL,Espacio);
			return;
		}
	}
	//Si no hay ninguno más pequeño al final
	lista.push_back(Espacio);
}
void CONTAINER::InsertarOrdenFlag(std::list< SPACE > & lista, SPACE &Espacio)
{
	//Por si solamente hay uno
	if (lista.size()==0)
	{
		lista.push_back(Espacio);
		return;
	}
	std::list<SPACE> ::iterator itlL;
	for (itlL=lista.begin();itlL!=lista.end();itlL++)
	{
		if((*itlL).Get_Flag()==false)
		{
			if ((*itlL).Get_Volumen()>Espacio.Get_Volumen())
			{
				lista.insert(itlL,Espacio);
				return;
			}
		}
	}
	//Si no hay ninguno más pequeño al final
	lista.push_back(Espacio);
}
void CONTAINER::EliminarInclusiones()
{
	std::list<SPACE> ::iterator itl,itl2;
/*	for (itl=m_Spaces.begin();itl!=m_Spaces.end();itl++)
	{
		SPACE E=(*itl);
	}
	
	*/	std::list < SPACE > ::iterator itfin=m_Spaces.end();
	for (itl=m_Spaces.begin();itl!=itfin;)
	{
//		SPACE kk=(*itl);
		itl2=itl;
		itl2++;
		if (itl2==itfin)
			break;
		bool borrado=false;
		for (;itl2!=itfin;itl2++)
		{
			
			if ((*itl).Incluido((*itl2))==true)
			{
				//Me devuelve el puntero que apunta al siguiente
				//por tanto le tengo que quita algo
				borrado=true;
				itl=m_Spaces.erase(itl);
				break;
			}
		}
		if (borrado==true) 
			++itl;
	}
}
void CONTAINER::EliminarInclusionesNuevos(std::list < SPACE > &Lista)
{
	std::list<SPACE> ::iterator itl,itl2;
	for (itl=Lista.begin();itl!=Lista.end();itl++)
	{

		itl2=itl;
		itl2++;

		if (itl2==Lista.end())
			break;
		for (;itl2!=Lista.end();itl2++)
		{
			
			if ((*itl2).Get_Volumen()<(*itl).Get_Volumen()) 
				continue;
			if ((*itl).Incluido(*itl2)==true)
			{

				//Me devuelve el puntero que apunta al siguiente
				//por tanto le tengo que quita algo
				itl=Lista.erase(itl);
				if (Lista.size()!=0)
				{
					if (itl!=Lista.begin())
						itl--;
				}
				else
					return;
					break;
			}
		}
	}
}
void CONTAINER::EliminarInclusionesListaAntigua(std::list <SPACE > &Lista)
{
	std::list<SPACE> ::iterator itl;
	std::list<SPACE> ::reverse_iterator itl2;
	for (itl=Lista.begin();itl!=Lista.end();itl++)
	{
		for (itl2=m_Spaces.rbegin();itl2!=m_Spaces.rend();itl2++)
		{
//			SPACE kk2=(*itl2);
			if ((*itl2).Get_Volumen()<(*itl).Get_Volumen()) 
				break;
			if ((*itl).Incluido((*itl2))==true)
			{
				//Si esta incluido termina 
				itl=Lista.erase(itl);
				if (Lista.size()!=0)
				{
					if (itl!=Lista.begin())
						itl--;
				}
				else return;
				break;
			}
		}
	}
}
void CONTAINER::EliminarListaTempListaOriginal(std::list <SPACE > &ListaOriginal,std::list <SPACE > &Lista)
{
	std::list<SPACE> ::iterator itl;
	std::list<SPACE> ::reverse_iterator itl2;
	for (itl=Lista.begin();itl!=Lista.end();itl++)
	{
//		SPACE kk=(*itl);
//		itl2=itl;
//		itl2++;
//		if (itl2==m_Spaces.end())
//			break;
		for (itl2=ListaOriginal.rbegin();itl2!=ListaOriginal.rend();itl2++)
		{
//			SPACE kk2=(*itl2);
			if ((*itl2).Get_Volumen()<(*itl).Get_Volumen()) 
				break;
			if ((*itl).Incluido((*itl2))==true)
			{
				//Si esta incluido termina 
				itl=Lista.erase(itl);
				if (Lista.size()!=0)
				{
					if (itl!=Lista.begin())
						itl--;
				}
				else return;
				break;
			}
		}
	}
}
bool SPACE::Incluido(SPACE &E)
{	
	
	//Esta incluido
	if (m_x1>= E.Get_x1() && m_x2<=E.Get_x2() 
		&& m_y1>= E.Get_y1() && m_y2<=E.Get_y2() 
		&& m_z1>= E.Get_z1() && m_z2<=E.Get_z2())
		return true;
	return false;
}

void CONTAINER::VerificarSolucion(std::list<CONFIGURACAO> &lista)
{
	return;
	if (ComprobarConfiguracaosNoIntersectan(lista)==true) 
	{

		//printf("Problemas con las configuracaos, se cortan");
		exit(3);
	}

	if (ComprobarTodosPosible(lista)==true)
	{
		for(int i=0;;)
		//printf("Tamano es %d %d,Un espacio o una configuracao tiene mal las coordenadas o pone más piezas de las permitidas",m_Spaces.size(),m_Configuracaos.size());
		exit(2);
		
	}
	if (ComprobarConfiguracaosNoIntersectanSpaces()==true) 
	{
		for(int i=0;;)

//		printf("Problemas con las co/nfiguracaos, se cortan con los espacios vacios");
		exit(4);
	}

}
bool CONTAINER::ComprobarConfiguracaosNoIntersectan(std::list<CONFIGURACAO> &lista)
{
//	return;
	std::list< CONFIGURACAO >::iterator itB1,itB2,itB3;
	for(itB1=lista.begin();itB1!=lista.end();itB1++)
	{
		itB2=itB1;
		itB2++;
		if (itB2==lista.end()) break;
		for(itB3=itB2;itB3!=lista.end();itB3++)
		{
			if( (*itB1).Get_x1()>=(*itB3).Get_x2() || (*itB3).Get_x1()>=(*itB1).Get_x2() )
				continue;
			if( (*itB1).Get_y1()>=(*itB3).Get_y2() || (*itB3).Get_y1()>=(*itB1).Get_y2() )
				continue;	
			if( (*itB1).Get_z1()>=(*itB3).Get_z2() || (*itB3).Get_z1()>=(*itB1).Get_z2() )
				continue;
			CONFIGURACAO E1=(*itB1);
			CONFIGURACAO E2=(*itB3);
			for (int i=0;;)
				printf("mierda");
			return true;

		}
	}
	return false;
}
bool CONTAINER::ComprobarTodosPosible(std::list<CONFIGURACAO> &lista)
{
	std::list< CONFIGURACAO >::iterator itB1;
	std::list< SPACE >::iterator itB3;
	//Comprobar que todas tenga el numero de piezas que pone
	for (int ik=0;ik<m_Q;ik++)
	{	
		int utili=m_Pieces[ik].Get_Num();
		int kk=0;
		for(itB1=lista.begin();itB1!=lista.end();itB1++)
		{
			if ((*itB1).Get_Id()==ik)
				kk+=(*itB1).Get_Num();
		}
		if (utili!=kk)
			return true;
	}
	//sumo todas las que he`puesto de una pieza y que no sobrepasen las que teni
	for (int ik=0;ik<m_Q;ik++)
	{	
		int kk=m_Pieces[ik].Get_Num();
		int utili=0;
		for(itB1=lista.begin();itB1!=lista.end();itB1++)
		{
			if ((*itB1).Get_Id()==ik)
				utili+=(*itB1).Get_Num();
		}
		if (utili>m_Pieces[ik].Get_q())
			return true;
	}
	int val=0;
	int val2=0;
	for(itB1=lista.begin();itB1!=lista.end();itB1++)
	{
			CONFIGURACAO b1=(*itB1);
		val+=(((*itB1).Get_x2()-(*itB1).Get_x1())*((*itB1).Get_y2()-(*itB1).Get_y1())*((*itB1).Get_z2()-(*itB1).Get_z1()));
		val2+=(*itB1).Get_Volumen();
		if((*itB1).Get_x1()>=0 && m_X>=(*itB1).Get_x2() &&
		   (*itB1).Get_y1()>=0 && m_Y>=(*itB1).Get_y2()  &&
		   (*itB1).Get_z1()>=0 && m_Z>=(*itB1).Get_z2() && (*itB1).Get_Num()<=m_Pieces[(*itB1).Get_Id()].Get_q() )
			continue;
		return true;


	}
	if (val!=m_total_volumen_ocupado)
		return true;
	for(itB3=m_Spaces.begin();itB3!=m_Spaces.end();itB3++)
	{
			SPACE b2=(*itB3);

		if((*itB3).Get_x1()>=0 && m_X>=(*itB3).Get_x2() &&
		   (*itB3).Get_y1()>=0 && m_Y>=(*itB3).Get_y2()  &&
		   (*itB3).Get_z1()>=0 && m_Z>=(*itB3).Get_z2() )
		   continue;
		return true;

	}

	return false;
}

bool CONTAINER::ComprobarConfiguracaosNoIntersectanSpaces()
{
//	return;
	std::list< CONFIGURACAO >::iterator itB1;
	std::list< SPACE >::iterator itB3;
	for(itB1=m_Configuracaos.begin();itB1!=m_Configuracaos.end();itB1++)
	{
		for(itB3=m_Spaces.begin();itB3!=m_Spaces.end();itB3++)
		{
//			BLOQUE b1=(*itB1);
//			BLOQUE b2=(*itB2);
			if ((*itB3).Get_Flag()==true) continue;
			if( (*itB1).Get_x1()>=(*itB3).Get_x2() || (*itB3).Get_x1()>=(*itB1).Get_x2() )
				continue;
			if( (*itB1).Get_y1()>=(*itB3).Get_y2() || (*itB3).Get_y1()>=(*itB1).Get_y2() )
				continue;	
			if( (*itB1).Get_z1()>=(*itB3).Get_z2() || (*itB3).Get_z1()>=(*itB1).Get_z2() )
				continue;
			CONFIGURACAO C=(*itB1);
			SPACE E=(*itB3);
			return true;

		}
	}
	return false;
}



void CONTAINER:: EscribirSolucion()
{
	FILE *fin3;
	fin3=fopen("Result2.txt","a+");
	fprintf(fin3,"%d\n",m_max_total_volumen_ocupado);
	std::list< CONFIGURACAO > ::iterator it;
	for (it=m_Configuracaos.begin();it!=m_Configuracaos.end();it++)
	{
		fprintf(fin3,"(%d %d) (%d %d) Pieza %d \n",(*it).Get_x1(),(*it).Get_y1(),(*it).Get_x2(),(*it).Get_y2(),(*it).Get_Id());
	}
	fclose(fin3);
}
void CONTAINER:: EscribirMejorSolucion(std::list<CONFIGURACAO> lista)
{
	

	FILE *fin3;
	char string[200];
	strcpy(string,"Sol200000");
	//Primero buscamos la ultima ocurrencia de 
	int ch='\\';
	char *ultimo=strrchr( m_Nombre, ch );
	strcat(string,ultimo+1);

	fin3=fopen(string,"w+");
	fprintf(fin3,"%d\t%d\n",m_max_total_volumen_ocupado,m_total_volumen_ocupado);
	std::list< CONFIGURACAO > ::iterator itC;
	float divide=20;
//	fprintf(fin3,"\\CubeThreeD[ A=%.3f,B=%.3f,C=%.3f](%.3f,%.3f,%.3f)\n",(double)m_Y/20,(double)m_X/20,(double)m_Z/20,(double)m_Y/20,(double)m_X/20,(double)m_Z/20);


	//Ahora las lineas que van de un lado al otro
	//Esto dibuja bloque enteros de piezas
	for (itC=lista.begin();itC!=lista.end();itC++)
	{
		for (int register i=1;i<=(*itC).Get_dx();i++)
		{
			int sumoi=(((*itC).Get_x2()-(*itC).Get_x1())/(*itC).Get_dx());

			for (int register j=1;j<=(*itC).Get_dy();j++)
			{
				int sumoj=(((*itC).Get_y2()-(*itC).Get_y1())/(*itC).Get_dy());

				for (int register k=1;k<=(*itC).Get_dz();k++)
				{

					int sumok=(((*itC).Get_z2()-(*itC).Get_z1())/(*itC).Get_dz());
//					CONFIGURACAO kk=(*itC);
//					DibujarCaja3D((*itC).Get_x1(),(*itC).Get_y1(),(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x2(),(*itC).Get_y2(),(*itC).Get_z1()+k*sumok,(*itC).Get_Id());
//					DibujarCaja3D((*itC).Get_x1(),(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1(),(*itC).Get_x2(),(*itC).Get_y1()+j*sumoj,(*itC).Get_z2(),(*itC).Get_Id());
					fprintf(fin3,"%d\t%d\t%d\t%d\t%d\t%d\t%d\n",(*itC).Get_x1()+(i-1)*sumoi,(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi,(*itC).Get_y1()+j*sumoj,(*itC).Get_z1()+k*sumok,(*itC).Get_Id());


				}
			}
		}
	}
	fclose(fin3);
}
void CONTAINER:: EscribirSolucionLatex(std::list<CONFIGURACAO> lista)
{
	
	m_tipo_gravedad=2;
	lista.sort();

	FILE *fin3;
	char string[200];
	strcpy(string,"Latex");
	//Primero buscamos la ultima ocurrencia de 
	int ch='\\';
	char *ultimo=strrchr( m_Nombre, ch );
	strcat(string,ultimo+1);

	fin3=fopen(string,"w+");
	fprintf(fin3,"%d\n",m_max_total_volumen_ocupado);
	std::list< CONFIGURACAO > ::iterator itC;
	float divide=20;
//	fprintf(fin3,"\\CubeThreeD[ A=%.3f,B=%.3f,C=%.3f](%.3f,%.3f,%.3f)\n",(double)m_Y/20,(double)m_X/20,(double)m_Z/20,(double)m_Y/20,(double)m_X/20,(double)m_Z/20);


	//Ahora las lineas que van de un lado al otro
	//Esto dibuja bloque enteros de piezas
	for (itC=lista.begin();itC!=lista.end();itC++)
	{
		for (int register i=1;i<=(*itC).Get_dx();i++)
		{
			int sumoi=(((*itC).Get_x2()-(*itC).Get_x1())/(*itC).Get_dx());

			for (int register j=1;j<=(*itC).Get_dy();j++)
			{
				int sumoj=(((*itC).Get_y2()-(*itC).Get_y1())/(*itC).Get_dy());

				for (int register k=1;k<=(*itC).Get_dz();k++)
				{

					int sumok=(((*itC).Get_z2()-(*itC).Get_z1())/(*itC).Get_dz());
//					CONFIGURACAO kk=(*itC);
//					DibujarCaja3D((*itC).Get_x1(),(*itC).Get_y1(),(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x2(),(*itC).Get_y2(),(*itC).Get_z1()+k*sumok,(*itC).Get_Id());
//					DibujarCaja3D((*itC).Get_x1(),(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1(),(*itC).Get_x2(),(*itC).Get_y1()+j*sumoj,(*itC).Get_z2(),(*itC).Get_Id());

					fprintf(fin3," \\CubeThreeD[ A=\t%.3f\t,B=\t%.3f\t,C=\t%.3f\t](\t%.3f\t,\t%.3f\t,\t%.3f\t)\n",
						(double)sumoj/20,(double)sumoi/20,(double)sumok/20,
					(double)((*itC).Get_y1()+(double)(j-1)*sumoj+sumoj/2)/10,
					(double)((*itC).Get_x1()+(double)(i-1)*sumoi+sumoi/2)/10,
					(double)((*itC).Get_z1()+(double)(k-1)*sumok+sumok/2)/10);
					

				}
			}
		}
	}
	fclose(fin3);
}
void CONTAINER:: PintarSolucion(std::list<CONFIGURACAO> &lista)
{
	printf("\n");
	std::list< CONFIGURACAO > ::iterator it;
	for (it=lista.begin();it!=lista.end();it++)
	{
		printf("(%d %d %d) (%d %d %d) Pieza %d  Cantidad %d max %d \n",(*it).Get_x1(),(*it).Get_y1(),(*it).Get_z1(),(*it).Get_x2(),(*it).Get_y2(),(*it).Get_z2(),(*it).Get_Id(),(*it).Get_Num(),m_Pieces[(*it).Get_Id()].Get_q());
	}
	printf("\n");


}
//Esta funcion mueve las cajas en un sentido 
bool CONTAINER::FuerzaDeGravedad(std::list<CONFIGURACAO> &lista,short int sentido)
{
	bool movido=false;
	//Las ordenamos por el eje que toque
//	//el sentido es hacia donde la puedo mover 
//	BubbleSort(m_Best_Configuracao,0);
	//Esta variable es para que las tenga ordenadas de la forma
	//que queramos
	m_tipo_gravedad=sentido;
	lista.sort();
	//0 eje_z
	//1 eje_x
	//2 eje_y
//	PintarSolucion(m_Best_Configuracao);
//	sentido=0;
	std::list<CONFIGURACAO> ::iterator itC;
	for (itC=lista.begin();itC!=lista.end();itC++)
	{
//		CONFIGURACAO kk=(*itC);
		if (sentido==0 && (*itC).Get_z1()==0) continue;
		if (sentido==1 && (*itC).Get_x1()==0) continue;
		int muevo=PuedoMover(lista,(*itC).Get_x1(),(*itC).Get_y1(),(*itC).Get_z1(),(*itC).Get_x2(),(*itC).Get_y2(),(*itC).Get_z2(),sentido);
		if (sentido==0 && muevo>0)
		{
			movido=true;
			(*itC).Set_z1((*itC).Get_z1()-muevo);
			(*itC).Set_z2((*itC).Get_z2()-muevo);
		}
		if (sentido==1 && muevo>0)
		{
			movido=true;
			(*itC).Set_x1((*itC).Get_x1()-muevo);
			(*itC).Set_x2((*itC).Get_x2()-muevo);
		}
		if (sentido==2 && muevo>0)
		{
			movido=true;
			(*itC).Set_y1((*itC).Get_y1()-muevo);
			(*itC).Set_y2((*itC).Get_y2()-muevo);
		}
		// Para piezas
		/*
		for (int register i=1;i<=(*itC).Get_dx();i++)
		{
			int sumoi=(((*itC).Get_x2()-(*itC).Get_x1())/(*itC).Get_dx());

			for (int register j=1;j<=(*itC).Get_dy();j++)
			{
				int sumoj=(((*itC).Get_y2()-(*itC).Get_y1())/(*itC).Get_dy());

				for (int register k=1;k<=(*itC).Get_dz();k++)
				{
					int sumok=(((*itC).Get_z2()-(*itC).Get_z1())/(*itC).Get_dz());
					//Le paso las tres dimensiones y eta funcion me devuelve si la puedo mover y cuanto para abajo
					int muevo=PuedoMover((*itC).Get_x1()+(i-1)*sumoi,(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi,(*itC).Get_y1()+j*sumoj,(*itC).Get_z1()+k*sumok,(*itC).Get_Id(),sentido);
				}
			}
		}
		*/
	}
//	PintarSolucion(m_Best_Configuracao);
	return movido;

}
//Esta funcion mueve las cajas en un sentido 
bool CONTAINER::FuerzaDeGravedadIndividual(std::list<CONFIGURACAO> &lista,short int sentido)
{
	bool movido=false;
	//Las ordenamos por el eje que toque
//	//el sentido es hacia donde la puedo mover 
//	BubbleSort(m_Best_Configuracao,0);
	//Esta variable es para que las tenga ordenadas de la forma
	//que queramos
	m_tipo_gravedad=sentido;
	lista.sort();
	//0 eje_z
	//1 eje_x
	//2 eje_y
//	PintarSolucion(m_Best_Configuracao);
//	sentido=0;
	std::list<CONFIGURACAO> ::iterator itC,itC2;
	for (itC=lista.begin();itC!=lista.end();itC++)
	{
		CONFIGURACAO kk=(*itC);
		if (sentido==0 && (*itC).Get_z1()==0) continue;
		if (sentido==1 && (*itC).Get_x1()==0) continue;
		if (sentido==2 && (*itC).Get_y1()==0) continue;
		bool fini=false;
		// Para piezas
		for (int register i=1;i<=(*itC).Get_dx() && fini!=true;i++)
		{
			
			int sumoi=(((*itC).Get_x2()-(*itC).Get_x1())/(*itC).Get_dx());
			bool finj=false;
			for (int register j=1;j<=(*itC).Get_dy() && finj!=true;j++)
			{
				int sumoj=(((*itC).Get_y2()-(*itC).Get_y1())/(*itC).Get_dy());
				bool fink=false;

				for (int register k=1;k<=(*itC).Get_dz() && fink!=true;k++)
				{
					int sumok=(((*itC).Get_z2()-(*itC).Get_z1())/(*itC).Get_dz());
					//Si es en un sentido o en otro solamente tengo en cuenta 
					//para un lado
					if (sentido==0)
					{
						k=1;
						sumok=((*itC).Get_z2()-(*itC).Get_z1());
						fink=true;
					}
					if (sentido==1)
					{
						i=1;
						sumoi=((*itC).Get_x2()-(*itC).Get_x1());
						fini=true;

					}
					if (sentido==2)
					{
						j=1;
						sumoj=((*itC).Get_y2()-(*itC).Get_y1());
						finj=true;

					}
					int muevo=PuedoMover(lista,(*itC).Get_x1()+(i-1)*sumoi,(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi,(*itC).Get_y1()+j*sumoj,(*itC).Get_z1()+k*sumok,sentido);
					//Tengo que dividir la capa en trozos ya que una caja individual si la 
					//puedo bajar
//					CONFIGURACAO kk=(*itC);

					if (sentido==0 && muevo>0)
					{
//						//printf("algo se mueve");
						//Tengo que llamar a la funcion con la configuracion
						//que tengo 
						std::list< CONFIGURACAO > lista_Temp;
						//Tengo que meter algunas nuevas configuracaos
						ActualizarConfiguracaoGravedad((*itC),(*itC).Get_x1()+(i-1)*sumoi,(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi,(*itC).Get_y1()+j*sumoj,(*itC).Get_z1()+k*sumok,lista_Temp,sentido);
						//Cambio la actual configuracao
						//Tengo que poner el numero 
						itC->Set_x1((*itC).Get_x1()+(i-1)*sumoi);
						itC->Set_y1((*itC).Get_y1()+(j-1)*sumoj);
						itC->Set_x2((*itC).Get_x1()+sumoi);
						itC->Set_y2((*itC).Get_y1()+sumoj);
						itC->Set_dx(1);	
						itC->Set_dy(1);
						itC->Set_dz((*itC).Get_dz());
						itC->Set_Num((*itC).Get_dz());
						itC->Set_z1((*itC).Get_z1()-muevo);
						itC->Set_z2((*itC).Get_z2()-muevo);
						itC->Set_Vol(((*itC).Get_z2()-(*itC).Get_z1())*((*itC).Get_y2()-(*itC).Get_y1())*((*itC).Get_x2()-(*itC).Get_x1()));
						//Actualizar esta configuraco me crea algunas nuevas
						itC2=itC;
						if (itC!=lista.end()) itC2++;
						

						lista.insert(itC2,lista_Temp.begin(),lista_Temp.end());

						movido=true;
					}
					if (sentido==2 && muevo>0)
					{


//						printf("algo se mueve");
						int vol=(*itC).Get_Volumen();
						//Tengo que llamar a la funcion con la configuracion
						//que tengo 
						std::list< CONFIGURACAO > lista_Temp;
						//Tengo que meter algunas nuevas configuracaos
						ActualizarConfiguracaoGravedad((*itC),(*itC).Get_x1()+(i-1)*sumoi,(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi,(*itC).Get_y1()+j*sumoj,(*itC).Get_z1()+k*sumok,lista_Temp,sentido);

						movido=true;
						int numto=(*itC).Get_Num();
						itC->Set_z1((*itC).Get_z1()+(k-1)*sumok);
						itC->Set_z2((*itC).Get_z1()+sumok);
						itC->Set_x1((*itC).Get_x1()+(i-1)*sumoi);
						itC->Set_x2((*itC).Get_x1()+sumoi);
						//Pongo las piezas que tuviera en la direccion de x
						itC->Set_dx(1);	
						itC->Set_dy((*itC).Get_dy());
						itC->Set_dz(1);
						itC->Set_Num((*itC).Get_dy());
						itC->Set_y1((*itC).Get_y1()-muevo);
						itC->Set_y2((*itC).Get_y2()-muevo);
						itC->Set_Vol(((*itC).Get_z2()-(*itC).Get_z1())*((*itC).Get_y2()-(*itC).Get_y1())*((*itC).Get_x2()-(*itC).Get_x1()));
						std::list<CONFIGURACAO> ::iterator itkk;
						int vol2=(*itC).Get_Volumen();
						for (itkk=lista_Temp.begin();itkk!=lista_Temp.end();itkk++)
						{
							vol2+=(*itkk).Get_Volumen();
						}
						if (vol2!=vol)
							int kko=0;
						itC2=itC;
						if (itC!=lista.end()) itC2++;

						lista.insert(itC2,lista_Temp.begin(),lista_Temp.end());
					}				
					if (sentido==1 && muevo>0)
					{


//						printf("algo se mueve");

						//Tengo que llamar a la funcion con la configuracion
						//que tengo 
						std::list< CONFIGURACAO > lista_Temp;
						//Tengo que meter algunas nuevas configuracaos
						ActualizarConfiguracaoGravedad((*itC),(*itC).Get_x1()+(i-1)*sumoi,(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi,(*itC).Get_y1()+j*sumoj,(*itC).Get_z1()+k*sumok,lista_Temp,sentido);

						movido=true;
						int numto=(*itC).Get_Num();
						itC->Set_z1((*itC).Get_z1()+(k-1)*sumok);
						itC->Set_z2((*itC).Get_z1()+sumok);
						itC->Set_y1((*itC).Get_y1()+(j-1)*sumoj);
						itC->Set_y2((*itC).Get_y1()+sumoj);
						//Pongo las piezas que tuviera en la direccion de x
						itC->Set_dx((*itC).Get_dx());	
						itC->Set_dy(1);
						itC->Set_dz(1);
						itC->Set_Num((*itC).Get_dx());
						itC->Set_x1((*itC).Get_x1()-muevo);
						itC->Set_x2((*itC).Get_x2()-muevo);
						itC->Set_Vol(((*itC).Get_z2()-(*itC).Get_z1())*((*itC).Get_y2()-(*itC).Get_y1())*((*itC).Get_x2()-(*itC).Get_x1()));

						itC2=itC;
						if (itC!=lista.end()) itC2++;

						lista.insert(itC2,lista_Temp.begin(),lista_Temp.end());
					}
				}
			}
		}

	}
//	PintarSolucion(m_Best_Configuracao);
	return movido;

}
//Me dice  cuanto la puedo mover en alguna dirección
//o eje_z
//1 eje_x
//2 eje_y
int CONTAINER::PuedoMover(std::list<CONFIGURACAO> &lista,int x1,int y1,int z1,int x2,int y2,int z2,short int sentido)
{
	//Me dice cuanto puedo mover esta pieza 
	//lo primero es localizar el maximo
	//Lo primero es ver si se intersectan
	int mintemp=0,min=m_X;
	if (sentido==0)
		min=z1;
	if (sentido==1)
		min=x1;
	if (sentido==2)
		min=y1;
	std::list<CONFIGURACAO> ::iterator itC;
	for (itC=lista.begin();itC!=lista.end();itC++)
	{
//		CONFIGURACAO kk=(*itC);
		if (sentido==0)
		{
			if ((*itC).Get_z1()>=z1) 
				return min;
			if ((*itC).Get_z2()>z1) 
				continue;


			//Si no intersectan con eje_x
			if (!((x2 <= (*itC).Get_x1()) ||  (x1 >= (*itC).Get_x2()))
				&& !((y2 <= (*itC).Get_y1()) ||  (y1 >= (*itC).Get_y2())))
			{
			if (z1==((*itC).Get_z2())) 	return 0;
				mintemp=z1-((*itC).Get_z2());
			if (mintemp < min)
				min=mintemp;
			}
		}
		if (sentido==1)
		{
			if ((*itC).Get_x1()>=x1) return min;
			if ((*itC).Get_x2()>x1) continue;
			//Si intersectan con eje_x
			if (!(z2 <= (*itC).Get_z1() ||  z1 >= (*itC).Get_z2())
				&& !(y2 <= (*itC).Get_y1() ||  y1 >= (*itC).Get_y2()))
			{
				
			if ( x1==((*itC).Get_x2())) 				return 0;
			mintemp=x1-(*itC).Get_x2();
			if (mintemp < min)
				min=mintemp;
			}
		}
		if (sentido==2)
		{
			if ((*itC).Get_y1()>=y1) return min;
			if ((*itC).Get_y2()>y1) continue;
			//Si intersectan con eje_x
			if (!(z2 <= (*itC).Get_z1() ||  z1 >= (*itC).Get_z2())
				&& !(x2 <= (*itC).Get_x1() ||  x1 >= (*itC).Get_x2()))
			{
				
			if ( y1==((*itC).Get_y2())) 
				return 0;
			mintemp=y1-(*itC).Get_y2();
			if (mintemp < min)
				min=mintemp;
			}
		}

	}
	return 0;
}
void CONTAINER::BubbleSort(std::list<CONFIGURACAO> &lista,short int tipo) 
{
	std::list< CONFIGURACAO > ::iterator itc,itc2,itfin;
	bool fin;
	itfin=lista.end();
	do 
	{
		fin=true;
	    for (itc=lista.begin();itc!=itfin;itc++) 
		{
			PintarSolucion(lista);
			itc2=itc;
			itc2++;
//			CONFIGURACAO kk=(*itc);
//			CONFIGURACAO kk2=(*itc2);
			if (itc2==itfin)
			break;
			if ((*itc).Mayor((*itc2),tipo)==true) 
			{
				std::list< CONFIGURACAO > ::iterator ittemp;
				ittemp=itc;
				itc=itc2;
				itc2=ittemp;
	            fin=false;
				PintarSolucion(lista);
		
			}
		}
//		PintarSolucion(lista);

	} while (fin==false);
} 
bool CONFIGURACAO::Mayor(CONFIGURACAO &C,short int tipo)
{
	//Por el eje z
	if (tipo==0)
	{
		//Si no son restringidas
		if ((m_z1)==(C.m_z1))
		{
			//Por la eficiencia
			if (m_x1==C.m_x1)
			{
				return (m_y1>C.m_y1);
			}
			else
				//Por el área
			return (m_x1>C.m_x1);
		}
		else
			return (m_z1>C.m_z1);
	}
}
double CONTAINER::Medida1Estabilidad(std::list<CONFIGURACAO> &lista)
{
	//Esta tiene que sumar por cuantas cajas de media esta soportada cada caja 
	//que no esta en el suelo
	int total=0;
	int numcaixas=0;
	int numcaixasTotales=0,numcaixas100por100=0,numcaixasCG=0,numcaixas55por100=0;
	std::list<CONFIGURACAO> ::iterator itC,itC2;
	for (itC=lista.begin();itC!=lista.end();itC++)
	{
//		CONFIGURACAO kk=(*itC);


		// Para piezas
		for (int register i=1;i<=(*itC).Get_dx() ;i++)
		{
			
			int sumoi=(((*itC).Get_x2()-(*itC).Get_x1())/(*itC).Get_dx());

			for (int register j=1;j<=(*itC).Get_dy();j++)
			{
				int sumoj=(((*itC).Get_y2()-(*itC).Get_y1())/(*itC).Get_dy());

				for (int register k=1;k<=(*itC).Get_dz() ;k++)
				{

					int sumok=(((*itC).Get_z2()-(*itC).Get_z1())/(*itC).Get_dz());
					//Si esta en el suelo no me vale para la tercera medida
					if (((*itC).Get_z1()+(k-1)*sumok)==0)
					{
						numcaixas100por100++;
						numcaixas55por100++;
						numcaixasCG++;
						numcaixasTotales++;
						continue;
					}
					int kkespia=1;
					int kkespia2=0;
					int x1=(*itC).Get_x1()+(i-1)*sumoi;
					int x2=(*itC).Get_x1()+(i)*sumoi;
					int y1=(*itC).Get_y1()+(j-1)*sumoj;
					int y2=(*itC).Get_y1()+(j)*sumoj;
					if (EstaCajaSoportada((*itC).Get_x1()+(i-1)*sumoi,(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi,(*itC).Get_y1()+j*sumoj,(*itC).Get_z1()+k*sumok,lista,100)==true)
						numcaixas100por100++;
					if (EstaCajaSoportada((*itC).Get_x1()+(i-1)*sumoi,(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi,(*itC).Get_y1()+j*sumoj,(*itC).Get_z1()+k*sumok,lista,55)==true)
						numcaixas55por100++;
					else
						kkespia=0;
			
					int difx=sumoi/2;
					int dify=sumoj/2;
					if (2*difx==sumoi)
					{
						difx--;
					}
					if (2*dify==sumoj)
					{
						dify--;
					}
					if (numcaixas55por100==85)
						int kkk=9;
					if (EstaCajaSoportada((*itC).Get_x1()+(i-1)*sumoi+difx,(*itC).Get_y1()+(j-1)*sumoj+dify,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi-difx,(*itC).Get_y1()+j*sumoj-dify,(*itC).Get_z1()+k*sumok,lista,10)==true)
						numcaixasCG++;
					if (numcaixas55por100<numcaixasCG)
						int kkk=9;
					else kkespia2=1;
					if (kkespia==0 && kkespia2==0)
						int kkkit=0;

					numcaixasTotales++;
					total+=NumeroDeCajasSoportanEsta((*itC).Get_x1()+(i-1)*sumoi,(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi,(*itC).Get_y1()+j*sumoj,(*itC).Get_z1()+k*sumok,lista);

					numcaixas++;
				}
			}
		}
	}
	m_medidaCG=((double)numcaixasCG/(double)numcaixasTotales);
	m_medida100por100=((double)numcaixas100por100/(double)numcaixasTotales);
	m_medida60por100=((double)numcaixas55por100/(double)numcaixasTotales);
	//Medidas de estabilidad 1_1.1_2,1_3
	return ((double)total/(double)numcaixas);
}
//Cuanta el numero de cajas que soportan esta caja
int CONTAINER::NumeroDeCajasSoportanEsta(int x1,int y1, int z1, int x2, int y2, int z2,std::list<CONFIGURACAO> &lista)
{
	int numero=0;
	//Tengo que recorrer todas las cajas 
	std::list<CONFIGURACAO> ::iterator itC,itC2;
	for (itC=lista.begin();itC!=lista.end();itC++)
	{
		CONFIGURACAO kk=(*itC);
		// Para piezas
		for (int register i=1;i<=(*itC).Get_dx() ;i++)
		{
			
			int sumoi=(((*itC).Get_x2()-(*itC).Get_x1())/(*itC).Get_dx());

			for (int register j=1;j<=(*itC).Get_dy();j++)
			{
				int sumoj=(((*itC).Get_y2()-(*itC).Get_y1())/(*itC).Get_dy());

				for (int register k=1;k<=(*itC).Get_dz() ;k++)
				{

					int sumok=(((*itC).Get_z2()-(*itC).Get_z1())/(*itC).Get_dz());
					//Como ya tengo que lo soportan tengo que ver cuantas
					//cajas la soportan
					if (((*itC).Get_z1()+(k)*sumok)!=z1) continue;
					if (!((x2<=(*itC).Get_x1()+(i-1)*sumoi) ||  x1>=((*itC).Get_x1()+i*sumoi))
						&& !((y2<= (*itC).Get_y1()+(j-1)*sumoj) ||  y1>=((*itC).Get_y1()+j*sumoj)))
					{
						numero++;
					}

				}
			}
		}
	}
	return numero;
}	
//Cuanta el numero de cajas que soportan esta caja
int CONTAINER::EstaCajaSoportada(int x1,int y1, int z1, int x2, int y2, int z2,std::list<CONFIGURACAO> &lista,int cantidad)
{
	int numero=0;
	int areapieza=(x2-x1)*(y2-y1);
	int areacorta=0;
	//Tengo que recorrer todas las cajas 
	std::list<CONFIGURACAO> ::iterator itC,itC2;
	for (itC=lista.begin();itC!=lista.end();itC++)
	{
		CONFIGURACAO kk=(*itC);
		// Para piezas
		for (int register i=1;i<=(*itC).Get_dx() ;i++)
		{
			
			int sumoi=(((*itC).Get_x2()-(*itC).Get_x1())/(*itC).Get_dx());

			for (int register j=1;j<=(*itC).Get_dy();j++)
			{
				int sumoj=(((*itC).Get_y2()-(*itC).Get_y1())/(*itC).Get_dy());

				for (int register k=1;k<=(*itC).Get_dz() ;k++)
				{

					int sumok=(((*itC).Get_z2()-(*itC).Get_z1())/(*itC).Get_dz());
					//Como ya tengo que lo soportan tengo que ver cuantas
					//cajas la soportan
					if (((*itC).Get_z1()+(k)*sumok)!=z1) continue;
					if (!((x2<=(*itC).Get_x1()+(i-1)*sumoi) ||  x1>=((*itC).Get_x1()+i*sumoi))
						&& !((y2<= (*itC).Get_y1()+(j-1)*sumoj) ||  y1>=((*itC).Get_y1()+j*sumoj)))
					{
						int kk1=(*itC).Get_x1()+(i-1)*sumoi;
						int kk2=(*itC).Get_y1()+(j-1)*sumoj;
						//Aqui ahora tengo que ver cuanto se corta
						int minx1=__min(x1,((*itC).Get_x1()+(i-1)*sumoi));
						int miny1=__min(y1,((*itC).Get_y1()+(j-1)*sumoj));
						int maxx2=__max(x2,((*itC).Get_x1()+(i)*sumoi));
						int maxy2=__max(y2,((*itC).Get_y1()+(j)*sumoj));
						//Se corta en x
						int cx=(x2-x1)+(sumoi)-(maxx2-minx1);
						int cy=(y2-y1)+(sumoj)-(maxy2-miny1);
						areacorta+=cx*cy;
						if (areacorta>=((double)cantidad*areapieza/(double)100))
							return true;
						
					}

				}
			}
		}
	}
	return false;
}	
//Esta mide el número medio de cajas que tiene 3 lados pegados a otras cajas
	//Por tanto lo primero recorrer todas las cajas
double CONTAINER::Medida2Estabilidad(std::list<CONFIGURACAO> &lista)
{

	int total=0;
	int numcaixas=0;
	std::list<CONFIGURACAO> ::iterator itC,itC2;
	for (itC=lista.begin();itC!=lista.end();itC++)
	{
		// Para piezas
		for (int register i=1;i<=(*itC).Get_dx() ;i++)
		{
//			CONFIGURACAO kk=(*itC);
			int sumoi=(((*itC).Get_x2()-(*itC).Get_x1())/(*itC).Get_dx());

			for (int register j=1;j<=(*itC).Get_dy();j++)
			{
				int sumoj=(((*itC).Get_y2()-(*itC).Get_y1())/(*itC).Get_dy());

				for (int register k=1;k<=(*itC).Get_dz() ;k++)
				{
					int sumok=(((*itC).Get_z2()-(*itC).Get_z1())/(*itC).Get_dz());

					total+=EstaCajaTiene3Pegados((*itC).Get_x1()+(i-1)*sumoi,(*itC).Get_y1()+(j-1)*sumoj,(*itC).Get_z1()+(k-1)*sumok,(*itC).Get_x1()+i*sumoi,(*itC).Get_y1()+j*sumoj,(*itC).Get_z1()+k*sumok,lista);
					numcaixas++;
				}
			}
		}
	}
	return ((double)total/(double)numcaixas)*100;
}
//Cuanta el numero de cajas que soportan esta caja
int CONTAINER::EstaCajaTiene3Pegados(int x1,int y1, int z1, int x2, int y2, int z2,std::list<CONFIGURACAO> &lista)
{
	std::list<CONFIGURACAO> ::iterator itC,itC2;
	short int ladox1=0,ladox2=0,ladoy1=0,ladoy2=0;
	for (itC=lista.begin();itC!=lista.end();itC++)
	{

		// Para piezas
		for (int register i=1;i<=(*itC).Get_dx() ;i++)
		{
//			CONFIGURACAO kk=(*itC);
			int sumoi=(((*itC).Get_x2()-(*itC).Get_x1())/(*itC).Get_dx());

			for (int register j=1;j<=(*itC).Get_dy();j++)
			{
				int sumoj=(((*itC).Get_y2()-(*itC).Get_y1())/(*itC).Get_dy());
				//Para la z no tengo que hacerlo, vamos qu no es necesario
				//si intersecta con z
				if (!(z2<=(*itC).Get_z1() ||  z1>=(*itC).Get_z2()))
				{
					if ((*itC).Get_x1()+i*sumoi==x1 || x1==0)
						ladox1=1;
					if ((*itC).Get_x1()+(i-1)*sumoi==x2 || x2==m_X)
						ladox2=1;
					if ((*itC).Get_y1()+j*sumoj==y1 || y1==0)
						ladoy1=1;
					if ((*itC).Get_y1()+(j-1)*sumoj==y2 || y2==m_Y)
						ladoy2=1;
				}
			}
		}


	}
	int sum=ladox1+ladox2+ladoy1+ladoy2;
	if (sum>=3)
		return 0;
	else return 1;

}
/// CESCHIA CESCHIA CESCHIA!/// CESCHIA CESCHIA CESCHIA!/// CESCHIA CESCHIA CESCHIA!/// CESCHIA CESCHIA CESCHIA!/// CESCHIA CESCHIA CESCHIA!
/// CESCHIA CESCHIA CESCHIA!/// CESCHIA CESCHIA CESCHIA!/// CESCHIA CESCHIA CESCHIA!/// CESCHIA CESCHIA CESCHIA!/// CESCHIA CESCHIA CESCHIA!
void CONTAINER::MinimaDimension_Ceschia()
{	
	m_menor_peso=m_X*m_Y*m_Z;//-------------------------------------------
	m_dimension_menor=m_X;
	m_menor_volumen=m_X*m_Y*m_Z;
	int aux_menor_tipo;
	int aux_altura_densidad=0;
	for (int register icp=0;icp<m_Q;icp++)
	{
		if (m_Pieces[icp].Get_Num()==m_Pieces[icp].Get_q())
			continue;

		if ((m_Pieces[icp].Get_x()*m_Pieces[icp].Get_y()*m_Pieces[icp].Get_z())<m_menor_volumen)
			m_menor_volumen=m_Pieces[icp].Get_x()*m_Pieces[icp].Get_y()*m_Pieces[icp].Get_z();
		if (m_Pieces[icp].Get_x()<m_dimension_menor)
				m_dimension_menor=m_Pieces[icp].Get_x();
		if (m_Pieces[icp].Get_y()<m_dimension_menor)
				m_dimension_menor=m_Pieces[icp].Get_y();
		if (m_Pieces[icp].Get_z()<m_dimension_menor)
			m_dimension_menor=m_Pieces[icp].Get_z();
		
		aux_menor_tipo=m_Pieces[icp].Get_x();
		if (m_Pieces[icp].Get_y()<aux_menor_tipo)
			aux_menor_tipo=m_Pieces[icp].Get_y();
		if (m_Pieces[icp].Get_z()<aux_menor_tipo)
			aux_menor_tipo=m_Pieces[icp].Get_z();
		aux_altura_densidad=aux_menor_tipo*m_Pieces[icp].Get_m_densidad_pieza();
		if (m_menor_peso>aux_altura_densidad)
			m_menor_peso=aux_altura_densidad;
	}
}

void CONTAINER::ElegirSpace_Ceschia(SPACE &espacio, bool &posi)
{
	std::list<SPACE> ::iterator it,elegido;
	bool quedan_todavia=false;
	bool primero=true;
	//Los recorro todos comparando cual es el mejor
	std::list< SPACE > ::iterator itfin=m_Spaces.end();
	int kk=1;
	int eleccion=1;
	for (it=m_Spaces.begin();it!=itfin;kk++)
	{
		if ((*it).Get_Flag()==false)
		{
			quedan_todavia=true;
			if (primero==true) 
			{
				elegido=it;
				primero=false;
			}
			else
			{
				if (m_Aleatorizado==false)
				{
					if (m_full_supported==false)
					{
						if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
						{
							elegido=it;
						}
					}
					else
					{
						eleccion=get_random(1,3);
						switch(eleccion)
						{
							case 1:
							{	
								if ((*it).Get_z1()>(*elegido).Get_z1()) //OJO APILAR LUEGO CONTRALAPARED
									elegido=it;
								if ((*it).Get_z1()==(*elegido).Get_z1())
								{
									if ((*it).Get_x1()<(*elegido).Get_x1())//CONTRALAPARED
										elegido=it;
									if ((*it).Get_x1()==(*elegido).Get_x1())
									{
										if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
										{
											elegido=it;
										}
									}
								}
								break;
							}
							case 2:
							{				
								if ((*it).Get_x1()<(*elegido).Get_x1()) //OJO CONTRALAPARED LUEGO APILAR
									elegido=it;
								if ((*it).Get_x1()==(*elegido).Get_x1())
								{
									if ((*it).Get_z1()>(*elegido).Get_z1()) //APILAR
										elegido=it;
									if ((*it).Get_z1()==(*elegido).Get_z1())
									{
										if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
											elegido=it;		
									}
								}	
								break;
							}
							case 3:
							{
								if ((*it).Get_x1()<(*elegido).Get_x1()) // OJO CONTRALAPARED LUEGO NO APILAR
									elegido=it;
								if ((*it).Get_x1()==(*elegido).Get_x1())
								{
									if ((*it).Get_z1()<(*elegido).Get_z1()) //NOAPILAR
										elegido=it;
									if ((*it).Get_z1()==(*elegido).Get_z1())
									{
										if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
										elegido=it;		
									}
								}	
								break;
							}
						}
					}
				}
				else
				{	
					if (m_full_supported==false)
					{
						if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
						{
							elegido=it;
						}
					}
					else
					{
						eleccion=get_random(1,3);
						switch (eleccion)
						{
							case 1:
							{	
								if ((*it).Get_z1()>(*elegido).Get_z1()) //OJO APILAR LUEGO CONTRALAPARED
									elegido=it;
								if ((*it).Get_z1()==(*elegido).Get_z1())
								{
									if ((*it).Get_x1()<(*elegido).Get_x1())//CONTRALAPARED
										elegido=it;
									if ((*it).Get_x1()==(*elegido).Get_x1())
									{
										if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
										{
											elegido=it;
										}
									}
								}
								break;
							}
							
							case 2:
							{				
								if ((*it).Get_x1()<(*elegido).Get_x1()) //OJO CONTRALAPARED LUEGO APILAR
									elegido=it;
								if ((*it).Get_x1()==(*elegido).Get_x1())
								{
									if ((*it).Get_z1()>(*elegido).Get_z1()) //APILAR
										elegido=it;
									if ((*it).Get_z1()==(*elegido).Get_z1())
									{
										if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
											elegido=it;		
									}
								}
								break;
							}
							
							case 3:
							{
								if ((*it).Get_x1()<(*elegido).Get_x1()) // OJO CONTRALAPARED LUEGO NO APILAR
									elegido=it;
								if ((*it).Get_x1()==(*elegido).Get_x1())
								{
									if ((*it).Get_z1()<(*elegido).Get_z1()) //NOAPILAR
										elegido=it;
									if ((*it).Get_z1()==(*elegido).Get_z1())
									{
										if (Mejor_DistA_Que_DistB((*elegido),(*it))==false)
										elegido=it;		
									}
								}	
								break;
							}
						}	
					}
				}
			}
			++it;	
		}
		//Funcion que me elimina los espacios 
		//si la quito todo funsiona igual 
		else
		{
			it=m_Spaces.erase(it);
		}
	}
	if (quedan_todavia==false || m_Spaces.size()==0) 
	{
		return;
	}
	posi=true;
	espacio.ModificarSpacePeso(elegido->Get_x1(),elegido->Get_y1(),elegido->Get_z1(),elegido->Get_x2(),elegido->Get_y2(),elegido->Get_z2(),elegido->Get_m_soporta_peso(),elegido->Get_r_y1(),elegido->Get_r_y2(),elegido->Get_r_L());
}
void CONTAINER::ElegirConfiguracao_Ceschia(SPACE &Espacio,CONFIGURACAO &Configuracao, int cliente)	
{
	//Para el aleatorizado hago una estimacion que va a ser una estimacion d
	//los que puedo tener en la lista mas o menos
	if (m_Aleatorizado==true)
	{
		m_TamRCL=EstimacionPesoCliente_Ceschia(Espacio,cliente);
		if (m_TamRCL==0) 
		{
			int contador_piezas_cliente=0;
			int piezas_cliente_satisfechas=0;
			for (int imc=0;imc<m_Q;imc++)
			{	
				if(m_Pieces[imc].Get_Cliente()==cliente)
				{
					contador_piezas_cliente++;
					if(m_Pieces[imc].Get_Num()==m_Pieces[imc].Get_q())
					{
						piezas_cliente_satisfechas++;
					}
				}
			}
			if(piezas_cliente_satisfechas==contador_piezas_cliente)
				m_cambiar_cliente=true;		
			return;
		}

		m_TamRCL=ceil((double)m_TamRCL*m_Delta);

	}
	if (m_tipo_mixto==true)
	{
		if (get_random(0,1)==1)
			m_objetivo_capas=true;
		else
			m_objetivo_capas=false;
	}
	if (m_objetivo_capas==true)
	{
		int contador_piezas_cliente=0;
		int piezas_cliente_satisfechas=0;
		for (int imc=0;imc<m_Q;imc++)
		{	
			if(m_Pieces[imc].Get_Cliente()==cliente)
			{
				contador_piezas_cliente++;
				if (m_Pieces[imc].Get_Num()<m_Pieces[imc].Get_q())
				{				
					Configuracao.MejorCapaDeUnaPiezaPeso_Ceschia(Espacio,m_Pieces[imc]);
				}
				else
				{
					if(m_Pieces[imc].Get_Num()==m_Pieces[imc].Get_q())
					{
						piezas_cliente_satisfechas++;
					}
				}
			}
		}
		if(piezas_cliente_satisfechas==contador_piezas_cliente)
			m_cambiar_cliente=true;
	}
	else
	{
		for (int imc=0;imc<m_Q;imc++)
		{	
			if (m_Pieces[imc].Get_Num()<m_Pieces[imc].Get_q())
				//Cambiar para que vaya con columnas
				Configuracao.MejorColumnaDeUnaPieza(Espacio,m_Pieces[imc]);
		}
	}
	//Si es aleatorizado ya tengo todos ahora tengo que elegir uno
	if (m_Aleatorizado==true)
	{
		//Elegir uno al azar 
		//Puede ser que la estimacion sea por encima y luego no pueda
		//colocar tantas por esto
		int alea=get_random(0,__min(m_TamRCL-1,m_ListaRCL.size()-1));
		int cont=0;
		std::list < CONFIGURACAO > ::iterator it;
		for (it=m_ListaRCL.begin();it!=m_ListaRCL.end();it++)
		{
			if (alea==cont) 
			{
				//si es un bloque mas tarde lo voy a meter
				if ((*it).Get_Id()<1000)
				m_Configuracaos.push_back((*it));
//				m_total_volumen_ocupado+=(*it).Get_Volumen();
				Configuracao=(*it);
				m_ListaRCL.clear();
				return;
			}
			cont++;
		}
	}
	if (Configuracao.Get_Id()!=99999)
	{
		if (Configuracao.Get_Id()<1000)
			m_Configuracaos.push_back(Configuracao);
	}
}

int CONTAINER::EstimacionPesoCliente_Ceschia(SPACE &Espacio, int cliente)
{
	int estima=0;
	for (int icp=0;icp<m_Q;icp++)
	{
		if(m_Pieces[icp].Get_Cliente()==cliente)
		{
			if (m_Pieces[icp].Get_Num()<m_Pieces[icp].Get_q())
			{
				if (m_Pieces[icp].Get_Rz()==true)
				{
					estima+=EstimacionConEstaOrientacionPeso_Ceschia(Espacio,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_z()*m_Pieces[icp].Get_m_densidad_pieza());
					estima+=EstimacionConEstaOrientacionPeso_Ceschia(Espacio,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_z()*m_Pieces[icp].Get_m_densidad_pieza());
				}
				if (m_Pieces[icp].Get_Ry()==true)
				{
					estima+=EstimacionConEstaOrientacionPeso_Ceschia(Espacio,m_Pieces[icp].Get_x(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_y()*m_Pieces[icp].Get_m_densidad_pieza());
					estima+=EstimacionConEstaOrientacionPeso_Ceschia(Espacio,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_y()*m_Pieces[icp].Get_m_densidad_pieza());
				}
				if (m_Pieces[icp].Get_Rx()==true)
				{
					estima+=EstimacionConEstaOrientacionPeso_Ceschia(Espacio,m_Pieces[icp].Get_z(),m_Pieces[icp].Get_y(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_x()*m_Pieces[icp].Get_m_densidad_pieza());
					estima+=EstimacionConEstaOrientacionPeso_Ceschia(Espacio,m_Pieces[icp].Get_y(),m_Pieces[icp].Get_z(),m_Pieces[icp].Get_x(),m_Pieces[icp].Get_Id(),m_Pieces[icp].Get_q()-m_Pieces[icp].Get_Num(),m_Pieces[icp].Get_x()*m_Pieces[icp].Get_m_densidad_pieza());
				}
	//			estima=estima+estima_pieza;
			}
		}
	}
	return estima;
}
int CONTAINER::EstimacionConEstaOrientacionPeso_Ceschia(SPACE &Espacio, int x, int y,int z, int Id,int piezas_maximas, int fuerza)
{
	if (!(Espacio.Get_dx()>=x &&
		Espacio.Get_dy()>=y &&
		Espacio.Get_dz()>=z &&
		Espacio.Get_m_soporta_peso()>=fuerza))
		return 0;

	if (piezas_maximas==1) return 1;
	int suma=0;
	int Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
	int Eje_y=__min(Espacio.Get_dy()/y,piezas_maximas);
	int Eje_z;
	if(fuerza>0)
		Eje_z=__min(__min(Espacio.Get_dz()/z,piezas_maximas), Espacio.Get_m_soporta_peso()/fuerza);
	else
		Eje_z=__min(Espacio.Get_dz()/z,piezas_maximas);
	if (Eje_x>1)
		suma++;
	if (Eje_y>1)
		suma++;
	if (Eje_z>1)
		suma++;
	return suma;
}
void CONFIGURACAO::MejorCapaDeUnaPiezaPeso_Ceschia(SPACE &Espacio,PIECE &Pieza)
{
	int k=Pieza.Get_q()-Pieza.Get_Num();
	if (Pieza.Get_Rz()==true)
	{
		CompararConCapasPeso_Ceschia(1,Espacio,Pieza.Get_x(),Pieza.Get_y(),Pieza.Get_z(),Pieza.Get_Id(),k,(int)floor(Pieza.Get_z()*Pieza.Get_m_densidad_pieza()),Pieza.Get_m_densidad_pieza(),Pieza.Get_Sz(),Pieza.Get_Volumen(),Pieza.Get_Cliente(),Pieza.Get_Costo());
		CompararConCapasPeso_Ceschia(2,Espacio,Pieza.Get_y(),Pieza.Get_x(),Pieza.Get_z(),Pieza.Get_Id(),k,(int)floor(Pieza.Get_z()*Pieza.Get_m_densidad_pieza()),Pieza.Get_m_densidad_pieza(),Pieza.Get_Sz(),Pieza.Get_Volumen(),Pieza.Get_Cliente(),Pieza.Get_Costo());
	}
	if (Pieza.Get_Ry()==true)
	{
		CompararConCapasPeso_Ceschia(3,Espacio,Pieza.Get_x(),Pieza.Get_z(),Pieza.Get_y(),Pieza.Get_Id(),k,(int)floor(Pieza.Get_y()*Pieza.Get_m_densidad_pieza()),Pieza.Get_m_densidad_pieza(),Pieza.Get_Sy(),Pieza.Get_Volumen(),Pieza.Get_Cliente(),Pieza.Get_Costo());
		CompararConCapasPeso_Ceschia(4,Espacio,Pieza.Get_z(),Pieza.Get_x(),Pieza.Get_y(),Pieza.Get_Id(),k,(int)floor(Pieza.Get_y()*Pieza.Get_m_densidad_pieza()),Pieza.Get_m_densidad_pieza(),Pieza.Get_Sy(),Pieza.Get_Volumen(),Pieza.Get_Cliente(),Pieza.Get_Costo());
	}
	if (Pieza.Get_Rx()==true)
	{
		CompararConCapasPeso_Ceschia(5,Espacio,Pieza.Get_z(),Pieza.Get_y(),Pieza.Get_x(),Pieza.Get_Id(),k,(int)floor(Pieza.Get_x()*Pieza.Get_m_densidad_pieza()),Pieza.Get_m_densidad_pieza(),Pieza.Get_Sx(),Pieza.Get_Volumen(),Pieza.Get_Cliente(),Pieza.Get_Costo());
		CompararConCapasPeso_Ceschia(6,Espacio,Pieza.Get_y(),Pieza.Get_z(),Pieza.Get_x(),Pieza.Get_Id(),k,(int)floor(Pieza.Get_x()*Pieza.Get_m_densidad_pieza()),Pieza.Get_m_densidad_pieza(),Pieza.Get_Sx(),Pieza.Get_Volumen(),Pieza.Get_Cliente(),Pieza.Get_Costo());
	}
}
void CONFIGURACAO::CompararConCapasPeso_Ceschia(short int tipo,SPACE &Espacio, int x, int y,int z, int Id,int piezas_maximas,int fuerza, int densidad, int soporte, int Volumen, int Cliente, int Costo)
{
		int eleccion=1;
	//La pieza no cabe
	if (!(Espacio.Get_dx()>=x &&
		Espacio.Get_dy()>=y &&
		Espacio.Get_dz()>=z &&
		Espacio.Get_m_soporta_peso()>=fuerza))
		return;
	int Caso=1,numActual=1;
	//Tres posibles casos
	int Eje_x,Eje_y,Eje_z,Vol,Cos;
	for (Caso=1;Caso<=6;Caso++)
	{
		switch(m_Container->Get_Algoritmo_Opcion_Construccion())
		{
		case 1:
			{
				Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
				
			}break;
		case 2:
			{
				Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
				Eje_x=__min(1,Eje_x);
			}break;
		case 3:
			{
				eleccion=get_random(1,2);
				switch(eleccion)
				{
					case 1:
					{
						Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
					}break;
					case 2:
					{
						Eje_x=__min(Espacio.Get_dx()/x,piezas_maximas);
						Eje_x=__min(1,Eje_x);
					}break;
				}
			}break;
		}
		Eje_y=__min(Espacio.Get_dy()/y,piezas_maximas);
		if(fuerza>0)
			Eje_z=__min((soporte/fuerza)+1,__min(Espacio.Get_m_soporta_peso()/fuerza,__min(Espacio.Get_dz()/z,piezas_maximas)));
		else
			Eje_z=__min(Espacio.Get_dz()/z,piezas_maximas);
		//Para que si solo hay uno no haga ninguno mais
		if (Caso>1 && Eje_x==1 && Eje_y==1 && Eje_z==1 )
			break;
		switch (Caso)
		{
			case 1:
				{
					Eje_z=1;
					Eje_y=__min(Eje_y, (piezas_maximas/Eje_x));
					numActual=Eje_x*Eje_y;
					break;
				}
			case 2:
				{
					Eje_y=1;
					Eje_z=__min(Eje_z, (piezas_maximas/Eje_x));
					//Si no puedo colocar mas que una ya lo he hecho en el anterior
					if (Eje_z==1) continue;
					numActual=Eje_x*Eje_y;
					break;
				}
			case 3:
				{
					if (Eje_y==1) continue;
					Eje_x=__min(Eje_x, (piezas_maximas/Eje_y));
					if (Eje_x==1) continue;
					Eje_z=1;
					//en  y
					numActual=Eje_y*Eje_x;
					break;
				}
			case 4:
				{
					if (Eje_y==1) continue;
					Eje_x=1;
					Eje_z=__min(Eje_z, (piezas_maximas/Eje_y));
					if (Eje_z==1) continue;
					//en  y
					numActual=Eje_y*Eje_z;
					break;
				}
			// en z
			case 5:
				{
					if (Eje_z==1) continue;
					Eje_y=1;
					Eje_x=__min(Eje_x, (piezas_maximas/Eje_z));
					if (Eje_x==1) continue;

					numActual=Eje_z*Eje_x;
					break;
				}
			case 6:
				{
					if (Eje_z==1) continue;
					Eje_x=1;
					Eje_y=__min(Eje_y, (piezas_maximas/Eje_z));
					if (Eje_x==1) continue;
					numActual=Eje_z*Eje_y;
					break;
				}
		}
		//Tengo columnas ahora tengo que hacer caras con esa columna
		//En eje y 
		//Dimensiones de la pieza las naturales
		//en x, las demas son unas por tanto esta configuracao
		//Tengo que poner eje, que ya esta puesto por el espacio
		ORIG OrigActual;
		if (m_Container->Get_objetivo_vol()==false)	
			Cambiar(OrigActual,Espacio.Get_dx()-Eje_x*x,Espacio.Get_dy()-Eje_y*y,Espacio.Get_dz()-Eje_z*z);
		
		if(m_Container->Get_Algoritmo_Opcion_Ceschia())
		{
			Cos=Eje_x*Eje_y*Eje_z*Costo*Volumen;	
		}
		else
		{
			Cos=0;
			Vol=Eje_x*Eje_y*Eje_z*Volumen;
		}
		//Para el constructivo 
		if (m_Container->Get_Aleatorizado()==false)
		{
			if (m_Container->Get_Tipo_Mejora()!=3)
			{
				if (Mejor_DistA_Que_DistB_Configuracaos(m_set_distancias,m_num,OrigActual,numActual,Vol,Eje_x*x,Eje_y*y)==false)
				{
//				m_set_distancias.clear();
					m_set_distancias=OrigActual;
					CambiarConfiguracaoPeso_Ceschia(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, fuerza, Espacio,soporte,Vol,Cliente,Cos);
				}
			}
			else
			{
				if (Mejor_DistA_Que_DistB_FullSupported(m_set_distancias,m_num,OrigActual,numActual,Vol,Eje_x*x,Eje_y*y,Eje_z*z)==false)
				{
					m_set_distancias=OrigActual;
					CambiarConfiguracaoPeso_Ceschia(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, fuerza, Espacio,soporte,Vol,Cliente,Cos);
				}
			}
		}
		//Para hacer un constructivo aleatorizado
		//La diferencia es que aqui tengo que tener una lista que es la que me controla cuantos 
		//pueden caber 
		else
		{
			//Tengo que ver si puedo o no meterla en la lista 
			//En la configuracion que tengo es la pero posible

			//Esta funcion inserta esta en la RCL
			//y a su vez deja esta igual al minimo
			//FALTA
			if (m_Container->Get_objetivo_vol()==false)
			{
//				m_set_distancias.clear();
				m_set_distancias=OrigActual;
			}
			//CambiarConfiguracao(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, Espacio,Vol);
			CambiarConfiguracaoPeso_Ceschia(numActual, Eje_x,Eje_y,Eje_z,x, y, z, Id,tipo, fuerza, Espacio,soporte,Vol,Cliente,Cos);
			InsertarOrdenadaRCL_Ceschia(*this);
			if (m_Container->Get_objetivo_vol()==false)
			{
				m_set_distancias=(*m_Container->Get_ListaRCL().begin()).Get_Distancia();
			}
			m_num=(*m_Container->Get_ListaRCL().begin()).Get_Num();
		}
	}
}
void CONFIGURACAO::CambiarConfiguracaoPeso_Ceschia(int numpiezas, int ca,int cb, int cc, int a,int b,int c, int id, short int tipo_rota,int fuerza, SPACE &Espacio,int peso_soporta,int Vol, int Cliente,int Cos)
{
	m_Id=id;
	m_tipo=tipo_rota;

	//if tipo_rota 1 o 2 es lo que soporte z
	//if tipo_rota 3 o 4 es lo que soporte y
	//if tipo_rota 5 o 6 es lo que soporte x
	m_soporte_peso=Espacio.Get_m_soporta_peso();
	m_soporte_peso_arriba=__min(Espacio.Get_m_soporta_peso()-(fuerza*cc),peso_soporta-(fuerza*(cc-1)));
	m_dx=ca;
	m_dy=cb;
	m_dz=cc;
	m_num=ca*cb*cc;
	
	if(m_Container->Get_Algoritmo_Opcion_Ceschia())
	{
		m_Costo=Cos;
	}
	else
	{
		m_Volumen=Vol;
	}
	//
	m_cliente_config=Cliente;
	if (m_Id>=1000)
	{
		m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
		m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
		m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		return;
	}

	switch (Espacio.Get_origen_distancia())
	{
		case 1:
		{
			if(Espacio.Get_z1()>0 && m_Container->Get_Algoritmo_Opcion()==4)
			{
				if(a>=(Espacio.Get_dx()-Espacio.Get_r_L()))
				{
					m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
				}
				else
				{
					m_x1=Espacio.Get_x2()-Espacio.Get_r_L()-ca*a; m_x2=m_x1+ca*a;
				}
				if(b<=(Espacio.Get_r_y1()-Espacio.Get_y1()))
				{
					m_y2=Espacio.Get_r_y2(); m_y1=m_y2-cb*b;
				}
				else
				{
					m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
					
				}
				m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
			}
			else
			{
				m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
				m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
				m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
			}
		}
		break;
		case  2:
		{
			if(Espacio.Get_z1()>0 && m_Container->Get_Algoritmo_Opcion()==4)
			{
				if(a>=(Espacio.Get_dx()-Espacio.Get_r_L()))
				{
					m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
				}
				else
				{
					m_x1=Espacio.Get_x2()-Espacio.Get_r_L()-ca*a; m_x2=m_x1+ca*a;
				}
				if(b<=(Espacio.Get_y2()-Espacio.Get_r_y2()))
				{
					m_y1=Espacio.Get_r_y1(); m_y2=m_y1+cb*b;
				}
				else
				{
					m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
				}		
				m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
			}
			else
			{
				m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
				m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
				m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
			}
		}
		break;
		case 3:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  4:
		{
			m_x1=Espacio.Get_x1(); m_x2=m_x1+ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  5:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case  6:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z1=Espacio.Get_z1(); m_z2=m_z1+cc*c;
		}
		break;
		case  7:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y1=Espacio.Get_y1(); m_y2=m_y1+cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
		case  8:
		{
			m_x2=Espacio.Get_x2(); m_x1=m_x2-ca*a;
			m_y2=Espacio.Get_y2(); m_y1=m_y2-cb*b;
			m_z2=Espacio.Get_z2(); m_z1=m_z2-cc*c;
		}
		break;
	}
}
void CONFIGURACAO::InsertarOrdenadaRCL_Ceschia(CONFIGURACAO &Actual)
{
	//Por si solamente hay uno
	if (m_Container->Get_ListaRCL().size()==0)
	{
		m_Container->Get_ListaRCL().push_back(Actual);
		return;
	}
	//Si tengo mas de los que necesito como voy a meter uno
	//Si no hay ninguno más pequeño al final
	std::list< CONFIGURACAO > ::iterator itl;
	for (itl=m_Container->Get_ListaRCL().begin();itl!=m_Container->Get_ListaRCL().end();itl++)
	{
		if (m_Container->Get_objetivo_vol()==true)
		{
			if(m_Container->Get_Algoritmo_Opcion_Ceschia())
			{
				if ((*itl).Get_Costo()>Get_Costo())	
				{
					m_Container->Get_ListaRCL().insert(itl,Actual);
					if (m_Container->Get_ListaRCL().size()>m_Container->Get_TamRCL())
						m_Container->Get_ListaRCL().pop_front();
					return;
				}		
			}
			else
			{
				if ((*itl).Get_Volumen()>Get_Volumen())		
				{
					m_Container->Get_ListaRCL().insert(itl,Actual);
					if (m_Container->Get_ListaRCL().size()>m_Container->Get_TamRCL())
						m_Container->Get_ListaRCL().pop_front();
					return;
				}		
			}
		}
		else
		{
			if (Mejor_DistA_Que_DistB_FullSupported(m_set_distancias,m_num,(*itl).Get_Distancia(),(*itl).Get_Num(),(*itl).Get_Volumen(),(*itl).Get_x2()-(*itl).Get_x1(),(*itl).Get_y2()-(*itl).Get_y1(),(*itl).Get_z2()-(*itl).Get_z1())==false)
			{
				m_Container->Get_ListaRCL().insert(itl,Actual);
				if (m_Container->Get_ListaRCL().size()>m_Container->Get_TamRCL())
					m_Container->Get_ListaRCL().pop_front();
				return;
			}
		}
	}
	//Si es mas grande que todos los demas
	m_Container->Get_ListaRCL().push_back(Actual);
	if (m_Container->Get_ListaRCL().size()>m_Container->Get_TamRCL())
		m_Container->Get_ListaRCL().pop_front();
}
void CONTAINER::ActualizarListas_Ceschia(SPACE &EspacioT, CONFIGURACAO &Configuracao)
{
	
	//Primero actualizo el numero que  a su vez actualiza el flag
	m_Pieces[Configuracao.Get_Id()].Add_Num(Configuracao.Get_Num());
	int kk=m_Pieces[Configuracao.Get_Id()].Get_Num();
	if(Get_Algoritmo_Opcion_Ceschia())
	{
		m_total_costo_ocupado+=Configuracao.Get_Costo();
	}
	else
	{
		m_total_volumen_ocupado+=Configuracao.Get_Volumen();
		m_total_volumen_ocupado_cliente+=Configuracao.Get_Volumen();
	}
	//si he quitado una tipo de pieza
	//ReducirBloquesConEstaPieza(Configuracao.Get_Id(),Configuracao.Get_Num());
	if (m_Pieces[Configuracao.Get_Id()].Get_Num()==m_Pieces[Configuracao.Get_Id()].Get_q())
	{
		if ((m_Pieces[Configuracao.Get_Id()].Get_x()==m_dimension_menor
			||m_Pieces[Configuracao.Get_Id()].Get_y()==m_dimension_menor 
			||m_Pieces[Configuracao.Get_Id()].Get_z()==m_dimension_menor
			||m_Pieces[Configuracao.Get_Id()].Get_x()*m_Pieces[Configuracao.Get_Id()].Get_m_densidad_pieza()==m_menor_peso
			||m_Pieces[Configuracao.Get_Id()].Get_y()*m_Pieces[Configuracao.Get_Id()].Get_m_densidad_pieza()==m_menor_peso 
			||m_Pieces[Configuracao.Get_Id()].Get_z()*m_Pieces[Configuracao.Get_Id()].Get_m_densidad_pieza()==m_menor_peso))
		{
			MinimaDimension_Ceschia();
		}
	}
	//Ahora tengo que meter los nuevos espacios producidos por la configuracao 
	//ademas los tengo que meter en orden porque despues estarán ordenados y es ir colocandolos en le lugar correspondiente
	std::list< SPACE > lista_temp;	
	ActualizarEspaciosElegido_Ceschia(EspacioT,Configuracao,lista_temp);
	//Si encima no queda nada guardar 
//Eliminar este espacio
	std::list< SPACE > ::iterator it;
	//FALTA 
	for (it = m_Spaces.begin();it!=m_Spaces.end();it++)
	{
		if ((*it).Get_x1()==EspacioT.Get_x1() && (*it).Get_x2()==EspacioT.Get_x2() &&
			(*it).Get_y1()==EspacioT.Get_y1() && (*it).Get_y2()==EspacioT.Get_y2() &&
			(*it).Get_z1()==EspacioT.Get_z1() && (*it).Get_z2()==EspacioT.Get_z2() )
		{
			m_Spaces.erase(it);
			break;
		}
	}
	//Primero miro con los que hay ya que
	std::list< SPACE > ::iterator itfin=m_Spaces.end();
	for (it = m_Spaces.begin();it!=m_Spaces.end();)
	{
		//Si se intersectan hacer los espacios
		if (!(Configuracao.Get_x2() <= (*it).Get_x1() ||  Configuracao.Get_x1() >= (*it).Get_x2())
			&& !(Configuracao.Get_y2() <= (*it).Get_y1() ||  Configuracao.Get_y1() >= (*it).Get_y2())
			&& !(Configuracao.Get_z2() <= (*it).Get_z1() ||  Configuracao.Get_z1() >= (*it).Get_z2()))
		{
			ActualizarEspaciosElegido_Ceschia((*it),Configuracao,lista_temp);
			//Tengo que hacer el -- porque me apunta al siguiente
			it=m_Spaces.erase(it);
		}
		else
			++it;
	}
	//Buscar inclusiones pero solamente con  los nuevos entres ssi
	EliminarInclusionesNuevos(lista_temp);
	//Buscar inclusiones de los nuevos con los antiguos esta función me debería colocar ya las
	//nuevas ordenadas
	//Aqui pruebo si puede quitar alguno y es mas rapido
	EliminarInclusionesListaAntigua(lista_temp);
	ColocarOrdenadosNuevos(lista_temp);
}
void CONTAINER::ActualizarEspaciosElegido_Ceschia(SPACE &E, CONFIGURACAO &C,std::list <SPACE> &lista_temp)
{
	//Podemos tener seis posibles espacios nuevos
	int dimx=E.Get_x2()-E.Get_x1();
	int dimy=E.Get_y2()-E.Get_y1();
	int dimz=E.Get_z2()-E.Get_z1();
	

	//Izquierda: if (xE1-xC1)>0 espaço es ((xE1-xC1),yE2-yE1,zE2-zE1)  v: (xE1,yE1,zE1)
	if ((C.Get_x1()-E.Get_x1())>0)
	{
		//Si se da esto es un espacio en el que no voy a poder colocar nada 
		//Por ahora no lo creo
		if (m_dimension_menor<=__min(__min((C.Get_x1()-E.Get_x1()),dimy),dimz) && (m_menor_volumen<=((C.Get_x1()-E.Get_x1())*dimy*dimz)))
		{
			if (CabeAlguna(C.Get_x1()-E.Get_x1(),dimy,dimz)==true)
			{
				SPACE Espacio(this,E.Get_x1(),E.Get_y1(),E.Get_z1(),(C.Get_x1()-E.Get_x1()),dimy,dimz,E.Get_r_y1(),E.Get_r_y2(),(C.Get_x1()-E.Get_x1()),E.Get_Flag());
				Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso());
				InsertarOrden(lista_temp,Espacio);
			}
		}
	}


	//Derecha:  if (xC2-xE2)>0 espaço es ((xC2-xE2),yE2-yE1,zE2-zE1) v: (xC2,yE1,zE1)
	if ((E.Get_x2()-C.Get_x2())>0)
	{
		if (m_dimension_menor<=__min(__min((E.Get_x2()-C.Get_x2()),dimy),dimz) && (m_menor_volumen<=((E.Get_x2()-C.Get_x2())*dimy*dimz)))
		{
			if (CabeAlguna((E.Get_x2()-C.Get_x2()),dimy,dimz)==true)
			{
				SPACE Espacio(this,C.Get_x2(),E.Get_y1(),E.Get_z1(),(E.Get_x2()-C.Get_x2()),dimy,dimz,E.Get_r_y1(),E.Get_r_y2(),(E.Get_x2()-C.Get_x2()),E.Get_Flag());
				Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso());
				InsertarOrden(lista_temp,Espacio);
			}
		}
//		lista_temp.push_back(Espacio);
	}
	//Abajo
	//Abajo: if (yC1-yE1)>0 espaço es (xE2-xE1, (yC1-yE1),zE2-zE1) v: (xE1,yC1,zE1)
	if ((C.Get_y1()-E.Get_y1())>0)
	{
		if (m_dimension_menor<=__min(__min(dimx,(C.Get_y1()-E.Get_y1())),dimz) && (m_menor_volumen<=((C.Get_y1()-E.Get_y1())*dimx*dimz)))
		{
			if (CabeAlguna(dimx,(C.Get_y1()-E.Get_y1()),dimz  )==true)
			{
				if(E.Get_r_y1()<C.Get_y1())
				{		
					SPACE Espacio(this,E.Get_x1(),E.Get_y1(),E.Get_z1(),dimx,(C.Get_y1()-E.Get_y1()),dimz,E.Get_r_y1(),__min(E.Get_r_y2(),C.Get_y1()),E.Get_r_L(),E.Get_Flag());
					Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso());
					InsertarOrden(lista_temp,Espacio);
				}
			}
		}
//		lista_temp.push_back(Espacio);
	}

	//Arriba
	//Arriba:  if (yE2-yC2)>0 espaço es (xE2-xE1, (yE2-yC2),zE2-zE1) v: (xE1,yE1,zE1)
	if ((E.Get_y2()-C.Get_y2())>0)
	{
		if (m_dimension_menor<=__min(__min(dimx,(E.Get_y2()-C.Get_y2())),dimz) && (m_menor_volumen<=((E.Get_y2()-C.Get_y2())*dimx*dimz)))
		{
			if (CabeAlguna(dimx,(E.Get_y2()-C.Get_y2()),dimz  )==true)
			{
				if(E.Get_r_y2()>C.Get_y2())
				{
					SPACE Espacio(this,E.Get_x1(),C.Get_y2(),E.Get_z1(),dimx,(E.Get_y2()-C.Get_y2()),dimz,__max(E.Get_r_y1(),C.Get_y2()),E.Get_r_y2(),E.Get_r_L(), E.Get_Flag());
					Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso());
					InsertarOrden(lista_temp,Espacio);
				}
			}
		}
//		lista_temp.push_back(Espacio);
	}
	//Fuera
	//Furera: if (zE1-zC1)>0 espaço es (xE2-xE1,yE2-yE1, (zE1-zC1)) v: (xE1,yE1,zC1)
	if ((C.Get_z1()-E.Get_z1())>0)
	{
		if (m_dimension_menor<=__min(__min(dimx,dimy),(C.Get_z1()-E.Get_z1())) && (m_menor_volumen<=((C.Get_z1()-E.Get_z1())*dimx*dimy)))
		{
			if (CabeAlguna(dimx,dimy,(C.Get_z1()-E.Get_z1()) )==true)
			{	
				SPACE Espacio(this,E.Get_x1(),E.Get_y1(),E.Get_z1(),dimx,dimy,(C.Get_z1()-E.Get_z1()),E.Get_r_y1(),E.Get_r_y2(),E.Get_r_L(),E.Get_Flag());
				Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso());
				InsertarOrden(lista_temp,Espacio);
			}
		}
//		lista_temp.push_back(Espacio);
	}
	//Dentro
	//Dentro:  if (zC2-zE2)>0 espaço es (xE2-xE1,yE2-yE1, (zC2-zE2)) v: (xE1,yE1,zE1)
	if ((E.Get_z2()-C.Get_z2())>0)
	{
		if (m_full_supported==false)
		{
			if (m_dimension_menor<=__min(__min(dimx,dimy),(E.Get_z2()-C.Get_z2())) && (m_menor_volumen<=((E.Get_z2()-C.Get_z2())*dimx*dimy)) && (C.Get_m_soporte_peso_arriba()>=m_menor_peso))
			{
				if (CabeAlguna(dimx,dimy,(E.Get_z2()-C.Get_z2()) )==true)
				{
					if(Get_Algoritmo_Opcion()==4)
					{
						SPACE Espacio(this,E.Get_x1(),E.Get_y1(),C.Get_z2(),dimx,dimy,(E.Get_z2()-C.Get_z2()),E.Get_r_y1(), E.Get_r_y2(), __min((E.Get_r_L()-C.Get_dz()),0),E.Get_Flag());
						Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso_arriba());
						InsertarOrden(lista_temp,Espacio);
					}
					else
					{
						SPACE Espacio(this,E.Get_x1(),E.Get_y1(),C.Get_z2(),dimx,dimy,(E.Get_z2()-C.Get_z2()),E.Get_r_y1(), E.Get_r_y2(), E.Get_r_L(),E.Get_Flag());
						Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso_arriba());
						InsertarOrden(lista_temp,Espacio);
					}
				}
			}
		}
		else
		{
			//si es un bloque ya he metido antes la parte de arriba
			if (C.Get_Id()>=1000) return;
			if (m_dimension_menor<=__min(__min((C.Get_x2()-C.Get_x1()),(C.Get_y2()-C.Get_y1())),(E.Get_z2()-C.Get_z2())) && (m_menor_volumen<=((C.Get_x2()-C.Get_x1())*(C.Get_y2()-C.Get_y1())*(E.Get_z2()-C.Get_z2()))) && (C.Get_m_soporte_peso_arriba()>=m_menor_peso))
			{
				if (CabeAlguna((C.Get_x2()-C.Get_x1()),(C.Get_y2()-C.Get_y1()),(E.Get_z2()-C.Get_z2()) )==true)
				{
					SPACE Espacio(this,__max(C.Get_x1(),E.Get_x1()),__max(C.Get_y1(),E.Get_y1()),C.Get_z2(),(__min(C.Get_x2(),E.Get_x2())-__max(C.Get_x1(),E.Get_x1())),(__min(C.Get_y2(),E.Get_y2())-__max(C.Get_y1(),E.Get_y1())),(E.Get_z2()-C.Get_z2()),E.Get_r_y1(), E.Get_r_y2(), __min((E.Get_r_L()-C.Get_dz()),0),E.Get_Flag());	
					Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso_arriba());
					InsertarOrden(lista_temp,Espacio);
				}
			}
		}
	}
}


/// DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES
/// DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES
/// DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES DANESES
///// PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP
///// PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP
///// PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP PESOS SIN MULTIDROP
/// LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU
/// LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU
/// LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU LIU LIU LIU  LIU
void CONTAINER::ActualizarEspaciosElegido_Liu(SPACE &E, CONFIGURACAO &C,std::list <SPACE> &lista_temp)
{
	//Podemos tener seis posibles espacios nuevos
	int dimx=E.Get_x2()-E.Get_x1();
	int dimy=E.Get_y2()-E.Get_y1();
	int dimz=E.Get_z2()-E.Get_z1();


	//Derecha:  if (xC2-xE2)>0 espaço es ((xC2-xE2),yE2-yE1,zE2-zE1) v: (xC2,yE1,zE1)
	if ((E.Get_x2()-C.Get_x2())>0)
	{
		if (m_dimension_menor<=__min(__min((E.Get_x2()-C.Get_x2()),dimy),dimz) && (m_menor_volumen<=((E.Get_x2()-C.Get_x2())*dimy*dimz)))
		{
			if (CabeAlguna((E.Get_x2()-C.Get_x2()),dimy,dimz)==true)
			{
				SPACE Espacio(this,C.Get_x2(),E.Get_y1(),E.Get_z1(),(E.Get_x2()-C.Get_x2()),dimy,dimz,E.Get_r_y1(),E.Get_r_y2(),E.Get_r_L(),E.Get_Flag());
				Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso());
				InsertarOrden(lista_temp,Espacio);
			}
		}

	}
	//Abajo
	//Abajo: if (yC1-yE1)>0 espaço es (xE2-xE1, (yC1-yE1),zE2-zE1) v: (xE1,yC1,zE1)
	if ((C.Get_y1()-E.Get_y1())>0)
	{
		if (m_dimension_menor<=__min(__min(dimx,(C.Get_y1()-E.Get_y1())),dimz) && (m_menor_volumen<=((C.Get_y1()-E.Get_y1())*dimx*dimz)))
		{
			if (CabeAlguna(dimx,(C.Get_y1()-E.Get_y1()),dimz  )==true)
			{
				if(E.Get_r_y1()<C.Get_y1())
				{				
					SPACE Espacio(this,E.Get_x1(),E.Get_y1(),E.Get_z1(),dimx,(C.Get_y1()-E.Get_y1()),dimz,E.Get_r_y1(),__min(E.Get_r_y2(),C.Get_y1()),E.Get_r_L(),E.Get_Flag());
					Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso());
					InsertarOrden(lista_temp,Espacio);
				}
			}
		}
	}
	//Arriba
	//Arriba:  if (yE2-yC2)>0 espaço es (xE2-xE1, (yE2-yC2),zE2-zE1) v: (xE1,yE1,zE1)
	if ((E.Get_y2()-C.Get_y2())>0)
	{
		if (m_dimension_menor<=__min(__min(dimx,(E.Get_y2()-C.Get_y2())),dimz) && (m_menor_volumen<=((E.Get_y2()-C.Get_y2())*dimx*dimz)))
		{
			if (CabeAlguna(dimx,(E.Get_y2()-C.Get_y2()),dimz  )==true)
			{
				if(E.Get_r_y2()>C.Get_y2())
				{
					SPACE Espacio(this,E.Get_x1(),C.Get_y2(),E.Get_z1(),dimx,(E.Get_y2()-C.Get_y2()),dimz,__max(E.Get_r_y1(),C.Get_y2()),E.Get_r_y2(),E.Get_r_L(), E.Get_Flag());
					Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso());
					InsertarOrden(lista_temp,Espacio);
				}
			}
		}
	}
	//Dentro
	//Dentro:  if (zC2-zE2)>0 espaço es (xE2-xE1,yE2-yE1, (zC2-zE2)) v: (xE1,yE1,zE1)
	if ((E.Get_z2()-C.Get_z2())>0)
	{
		if (m_full_supported==false)
		{
			if (m_dimension_menor<=__min(__min(dimx,dimy),(E.Get_z2()-C.Get_z2())) && (m_menor_volumen<=((E.Get_z2()-C.Get_z2())*dimx*dimy)) )
			{	
				if (CabeAlguna(dimx,dimy,(E.Get_z2()-C.Get_z2()) )==true)
				{
					SPACE Espacio(this,E.Get_x1(),E.Get_y1(),C.Get_z2(),dimx,dimy,(E.Get_z2()-C.Get_z2()),E.Get_r_y1(), E.Get_r_y2(), __min((E.Get_r_L()-C.Get_dz()),0),E.Get_Flag());
					Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso_arriba());
					InsertarOrden(lista_temp,Espacio);
				}
			}
		}
		else
		{
			//si es un bloque ya he metido antes la parte de arriba
			if (C.Get_Id()>=1000) return;
			if (m_dimension_menor<=__min(__min((C.Get_x2()-C.Get_x1()),(C.Get_y2()-C.Get_y1())),(E.Get_z2()-C.Get_z2())) && (m_menor_volumen<=((C.Get_x2()-C.Get_x1())*(C.Get_y2()-C.Get_y1())*(E.Get_z2()-C.Get_z2()))) )
			{
				if (CabeAlguna((C.Get_x2()-C.Get_x1()),(C.Get_y2()-C.Get_y1()),(E.Get_z2()-C.Get_z2()) )==true)
				{
					SPACE Espacio(this,__max(C.Get_x1(),E.Get_x1()),__max(C.Get_y1(),E.Get_y1()),C.Get_z2(),(__min(C.Get_x2(),E.Get_x2())-__max(C.Get_x1(),E.Get_x1())),(__min(C.Get_y2(),E.Get_y2())-__max(C.Get_y1(),E.Get_y1())),(E.Get_z2()-C.Get_z2()),E.Get_r_y1(), E.Get_r_y2(), __min((E.Get_r_L()-C.Get_dz()),0),E.Get_Flag());	
					Espacio.Set_m_soporta_peso(C.Get_m_soporte_peso_arriba());
					InsertarOrden(lista_temp,Espacio);
				}
			}
		}
	}
}
/// JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA
/// JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA
/// JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA JUNQUEIRA
