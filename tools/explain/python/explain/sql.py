"""
 
    Copyright (c) 2018 Windhover Labs, L.L.C. All rights reserved.
 
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
 
  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
  3. Neither the name Windhover Labs nor the names of its contributors 
     may be used to endorse or promote products derived from this software
     without specific prior written permission.
 
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

"""

from abc import abstractmethod, ABCMeta


class SQLiteBacked(object):
    """An object that is represented by the contents of a SQLite database."""
    def __init__(self, database):
        self.database = database


class SQLiteRow(SQLiteBacked, dict):
    """An object that is represented by a single row in a database.

    Provides helper methods for accessing columns/attributes of the row.
    """
    _QUERY = 'SELECT {} FROM {} WHERE id=={}'

    def __init__(self, database, row):
        """Construct object given the database, table name, and row number."""
        super().__init__(database)
        # print(type(self), row)
        if not isinstance(row, int):
            raise TypeError('Row must be int. Got ' + repr(row))
        self.row = row
        self.refresh_row_cache()

    def __repr__(self):
        return '{}({})'.format(
            self.__class__.__name__,
            ', '.join('{}={!r}'.format(*c) for c in self.items()))

    def refresh_row_cache(self):
        c = self.database.execute(
            self._QUERY.format('*', self.table(), self.row))
        result = [(k[0], v) for k, v in zip(c.description, c.fetchone())]
        """:type: List[Tuple[str, Any]]"""
        self.update(result)

    @classmethod
    @abstractmethod
    def table(cls):
        raise NotImplementedError


class SQLiteCacheRow(SQLiteRow, metaclass=ABCMeta):
    ROW_CACHE = {}

    @classmethod
    def from_cache(cls, database, row):
        key = (database, cls, row)
        try:
            return SQLiteCacheRow.ROW_CACHE[key]
        except KeyError:
            row = cls(database, row)
            SQLiteCacheRow.ROW_CACHE[key] = row
            return row
