from sqlalchemy import create_engine
from db_model import Base
from dmt import diagram
engine = create_engine('sqlite:///obc_model.sqlite', echo=False)
Base.metadata.create_all(engine)
diagram.create_diagram('sqlite:///obc_model.sqlite', 'obc_model')  # create png
