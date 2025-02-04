#Lista os arquivos a serem adicionados
set(SRC_FILES 
)

#Adiciona ao executável no CMakeLists da pasta de origem
target_sources(${PROJECT_NAME} PRIVATE 
    ${SRC_FILES}
)
